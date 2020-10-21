/**
 * @File     security_viid.cpp
 * @brief
 * @DateTime 2018/8/4 11:36:40
 * @Author   Nanuns
 */
#include "gat1400_viid.h"
#include "httplib.h"
#include "gat1400_utils.h"
#include "gat1400_rest.h"
#include "gat1400_status_code.h"

using namespace httplib;

#define CONTENT_TYPE "application/*+JSON;charset=UTF-8"
                   //"application/VIID+JSON;charset=UTF-8"
static Headers get_common_req_header(const string& deviceId) {
    Headers headers = {
        { "Accept", "application/json,application/*+json" },
        //{ "Content-Type", CONTENT_TYPE },
        { "User-Identify", deviceId },
        { "User-Agent", "nan-gat1400/1.0" }
    };
    return headers;
}

/**
 * 1. 加密体
 *      A1 = username:realm:password
 *      A2 = mthod:uri
 * 2.加密后的数据
 *  • HA1
 *      HA1 = MD5(A1)=MD5(username:realm:password)
 *  • HA2
 *      如果qop值未指定或为"auth"则
 *          HA2 = MD5(A2)= MD5(method:uri)
 *      如果qop值为“auth-int”，则
 *          HA2 = MD5(A2)=MD5(method:uri:MD5(entityBody))
 * • response
 *      如果 qop 值为"auth"或"auth-int"
 *          response = MD5(HA1:nonce:nc:cnonce:qop:HA2)
 *      如果 qop 未指定，那么如下计算 response：
 *          response = MD5(HA1:nonce:HA2)
 */

/**
 *  http://www.webdav.org/specs/rfc2617.html
 *  WWW-Authenticate: Digest realm="firberhome", nonce="8qx43l7i"
 *  Authorization: Digest username="dbTest", realm="firberhome", nonce="8qx43l7i", uri="/VIID/System/Register",
 *                 algorithm="MD5", cnonce="wenminchen@126.com", nc=00000001, qop=auth, response="48164a9699ccec9345016d62bc27384e"
 */
int security_viid::sys_register(const char* ip, int port, const char* deviceId,
                                const char* username, const char* password) {
    int ret = checkAddress(ip, port);
    if (ret != 0) {
        printf("address incorrect\n");
        return ret;
    }
    if (!deviceId || strlen(deviceId) < 1) {
        printf("device ID invalid\n");
        return -1;
    }

    string msg = security_message_factory::makeRegisterMessage(deviceId);

    Headers headers = get_common_req_header(deviceId);
    Client cli(ip, port);
    cli.set_keep_alive(true);
    cli.set_digest_auth(username, password);
    if (auto res = cli.Post(SECURITY_URL_PATH_VIID_REGISTER, headers, msg, CONTENT_TYPE)) {
        //std::map<std::string, std::string> wwwauth;
        //bool ret = detail::parse_www_authenticate(res.value, wwwauth, is_proxy);
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("register failed %d\n", res->status);
            return -1;
        }
        security_response_status_t status;
        ret = msgFactory.parseResponseStatus(res->body.c_str(), status);
        if (0 != ret || SECURITY_STATUS_OK != status.StatusCode) {
            printf("parseResponseStatus failed %d, %s\n", status.StatusCode, status.StatusString.c_str());
            return -1;
        }
        this->ip = ip;
        this->port = port;
        this->deviceId = deviceId;
        this->username = username;
        this->password = password;
        registered = true;
        lastTime = gettime_ms();
    } else {
        auto err = res.error();
        printf("register failed %d\n", err);
        return -1;
    }
    printf("register success\n");
    return 0;
}

int security_viid::sys_unregister() {
    int ret;
    if (!registered) {
        return 0;
    }
    if (this->deviceId.empty()) {
        printf("device ID invalid\n");
        return -1;
    }
 
    string msg = security_message_factory::makeUnregisterMessage(this->deviceId.c_str());

    Headers headers = get_common_req_header(deviceId);
    Client cli(ip, port);
    cli.set_keep_alive(true);
    cli.set_digest_auth(this->username.c_str(), this->password.c_str());
    if (auto res = cli.Post(SECURITY_URL_PATH_VIID_UNREGISTER, headers, msg, CONTENT_TYPE)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("unregister failed %d\n", res->status);
            return -1;
        }
        security_response_status_t status;
        ret = msgFactory.parseResponseStatus(res->body.c_str(), status);
        if (0 != ret || SECURITY_STATUS_OK != status.StatusCode) {
            printf("parseResponseStatus failed %d, %s\n", status.StatusCode, status.StatusString.c_str());
            return -1;
        }
        registered = false;
    }
    else {
        auto err = res.error();
        printf("unregister failed %d\n", err);
        return -1;
    }
	printf("unregister success\n");
	return 0;
}

int security_viid::sys_keepalive() {
    int ret;
    if (!registered) {
        return -1;
    }
    if (this->deviceId.empty()) {
        printf("device ID invalid\n");
        return -1;
    }

    if (gettime_ms() - lastTime < 90 * 1000) {
        return 0;
    }

    string msg = security_message_factory::makeKeepaliveMessage(this->deviceId.c_str());

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    cli.set_keep_alive(true);
    if (auto res = cli.Post(SECURITY_URL_PATH_VIID_KEEPALIVE, headers, msg, CONTENT_TYPE)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("keepalive failed %d\n", res->status);
            return -1;
        }
        security_response_status_t status;
        ret = msgFactory.parseResponseStatus(res->body.c_str(), status);
        if (0 != ret || SECURITY_STATUS_OK != status.StatusCode) {
            printf("parseResponseStatus failed %d, %s\n", status.StatusCode, status.StatusString.c_str());
            return -1;
        }
    }
    else {
        auto err = res.error();
        printf("keepalive failed %d\n", err);
        return -1;
    }
    printf("keepalive success\n");
    return 0;
}

/**
 * @Method   sys_synctime
 * @Brief
 * @DateTime 2018-08-04T12:55:00+0800
 * @Modify   2018-08-04T12:55:00+0800
 * @Author   Nanuns
 * @return   [description]
 */
int security_viid::sys_synctime(security_system_time_t& time) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (this->deviceId.empty()) {
        printf("device ID invalid\n");
        return -1;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Get(SECURITY_URL_PATH_VIID_TIME, headers)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("synchorize system time failed %d\n", res->status);
            return -1;
        }
        ret = msgFactory.parseSystemTime(res->body.c_str(), time);
        if (0 != ret) {
            printf("parseSystemTime failed\n");
            return -1;
        }
        lastTime = gettime_ms();
    }
    else {
        auto err = res.error();
        printf("synchorize system time failed %d\n", err);
        return -1;
    }
    printf("synchorize system time success\n");
    return 0;
}


int security_viid::query_apes(const SecurityParams& params, security_apes_t& apes) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_APES);
    if (ret == 0) {
        ret = msgFactory.parseApeList(body.c_str(), apes);
    }
    return ret;
}

int security_viid::update_apes(const security_apes_t& apes) {
    string msg = security_message_factory::makeAPEListMessage(apes);
    return update_list(msg, SECURITY_URL_PATH_VIID_APES);
}

int security_viid::query_apss(const SecurityParams& params, security_apss_t& apss) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_APSS);
    if (ret == 0) {
        ret = msgFactory.parseApsList(body.c_str(), apss);
    }
    return ret;
}


int security_viid::query_tollgates(const SecurityParams& params, security_tollgates_t& tatollgates) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_TOLLGATES);
    if (ret == 0) {
        ret = msgFactory.parseTollgateList(body.c_str(), tatollgates);
    }
    return ret;
}

int security_viid::query_lanes(const SecurityParams& params, security_lanes_t& lanes) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_LANES);
    if (ret == 0) {
        ret = msgFactory.parseLaneList(body.c_str(), lanes);
    }
    return ret;
}


int security_viid::add_video_slices(const security_videoslices_t& slices) {
    string msg = security_message_factory::makeVideoSliceListMessage(slices);
    return add_list(msg, SECURITY_URL_PATH_VIID_VIDEOSLICES);
}

int security_viid::query_video_slices(const SecurityParams& params, security_videoslices_t& slices) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_VIDEOSLICES);
    if (ret == 0) {
        ret = msgFactory.parseVideoSliceList(body.c_str(), slices);
    }
    return ret;
}

int security_viid::query_video_slice(const char* id, security_videoslice_t& slice) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_VIDEOSLICESS);
    if (ret == 0) {
        ret = msgFactory.parseVideoSlice(body.c_str(), slice);
    }
    return ret;
}

int security_viid::update_video_slice(const char* id, const security_videoslice_t& slice) {
    string msg = security_message_factory::makeVideoSliceMessage(slice);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_VIDEOSLICESS);
}

int security_viid::delete_video_slice(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_VIDEOSLICESS);
}

int security_viid::query_video_slice_info(const char* id, security_videoslice_info_t& info) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_VIDEOSLICESS, SECURITY_URL_PATH_S_INFO);
    if (ret == 0) {
        ret = msgFactory.parseVideoSliceInfo(body.c_str(), info);
    }
    return ret;
}

int security_viid::update_video_slice_info(const char* id, const security_videoslice_info_t& info) {
    string msg = security_message_factory::makeVideoSliceInfoMessage(info);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_VIDEOSLICESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::delete_video_slice_info(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_VIDEOSLICESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::add_video_slice_data(const char* id, const char* buff) {
    return add_object(id, buff, SECURITY_URL_PATH_VIID_VIDEOSLICESS, SECURITY_URL_PATH_S_DATA);
}

int security_viid::query_video_slice_data(const char* id, string& buff) {
    return query_object(id, buff, SECURITY_URL_PATH_VIID_VIDEOSLICESS, SECURITY_URL_PATH_S_DATA);
}

int security_viid::delete_video_slice_data(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_VIDEOSLICESS, SECURITY_URL_PATH_S_DATA);
}


int security_viid::add_images(const security_images_t& images) {
    string msg = security_message_factory::makeImageListMessage(images);
    return add_list(msg, SECURITY_URL_PATH_VIID_IMAGES);
}

int security_viid::query_images(const SecurityParams& params, security_images_t& images) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_IMAGES);
    if (ret == 0) {
        ret = msgFactory.parseImageList(body.c_str(), images);
    }
    return ret;
}

int security_viid::query_image(const char* id, security_image_t& image) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_IMAGESS);
    if (ret == 0) {
        ret = msgFactory.parseImage(body.c_str(), image);
    }
    return ret;
}

int security_viid::update_image(const char* id, const security_image_t& image) {
    string msg = security_message_factory::makeImageMessage(image);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_IMAGESS);
}

int security_viid::delete_image(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_IMAGESS);
}

int security_viid::query_image_info(const char* id, security_image_info_t& info) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_IMAGESS, SECURITY_URL_PATH_S_INFO);
    if (ret == 0) {
        ret = msgFactory.parseImageInfo(body.c_str(), info);
    }
    return ret;
}

int security_viid::update_image_info(const char* id, const security_image_info_t& info) {
    string msg = security_message_factory::makeImageInfoMessage(info);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_IMAGESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::delete_image_info(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_IMAGESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::add_image_data(const char* id, const char* buff) {
    return add_object(id, buff, SECURITY_URL_PATH_VIID_IMAGESS, SECURITY_URL_PATH_S_DATA);
}

int security_viid::query_image_data(const char* id, string& buff) {
    return query_object(id, buff, SECURITY_URL_PATH_VIID_IMAGESS, SECURITY_URL_PATH_S_DATA);
}

int security_viid::delete_image_data(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_IMAGESS, SECURITY_URL_PATH_S_DATA);
}


int security_viid::add_files(const security_files_t& files) {
    string msg = security_message_factory::makeFileListMessage(files);
    return add_list(msg, SECURITY_URL_PATH_VIID_FILES);
}

int security_viid::query_files(const SecurityParams& params, security_files_t& files) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_FILES);
    if (ret == 0) {
        ret = msgFactory.parseFileList(body.c_str(), files);
    }
    return ret;
}

int security_viid::query_file(const char* id, security_file_t& file) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_FILESS);
    if (ret == 0) {
        ret = msgFactory.parseFile(body.c_str(), file);
    }
    return ret;
}

int security_viid::update_file(const char* id, const security_file_t& file) {
    string msg = security_message_factory::makeFileMessage(file);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_FILESS);
}

int security_viid::delete_file(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_FILESS);
}

int security_viid::query_file_info(const char* id, security_file_info_t& info) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_FILESS, SECURITY_URL_PATH_S_INFO);
    if (ret == 0) {
        ret = msgFactory.parseFileInfo(body.c_str(), info);
    }
    return ret;
}

int security_viid::update_file_info(const char* id, const security_file_info_t& info) {
    string msg = security_message_factory::makeFileInfoMessage(info);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_FILESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::delete_file_info(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_FILESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::add_file_data(const char* id, const char* buff) {
    return add_object(id, buff, SECURITY_URL_PATH_VIID_FILESS, SECURITY_URL_PATH_S_DATA);
}

int security_viid::query_file_data(const char* id, string& buf) {
    return query_object(id, buf, SECURITY_URL_PATH_VIID_FILESS, SECURITY_URL_PATH_S_DATA);
}

int security_viid::delete_file_data(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_FILESS, SECURITY_URL_PATH_S_DATA);
}


int security_viid::add_persons(const security_persons_t& persons) {
    string msg = security_message_factory::makePersonListMessage(persons);
    return add_list(msg, SECURITY_URL_PATH_VIID_PERSONS);
}

int security_viid::query_persons(const SecurityParams& params, security_persons_t& persons) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_PERSONS);
    if (ret == 0) {
        ret = msgFactory.parsePersonList(body.c_str(), persons);
    }
    return ret;
}

int security_viid::update_persons(const security_persons_t& persons) {
    string msg = security_message_factory::makePersonListMessage(persons);
    return update_list(msg, SECURITY_URL_PATH_VIID_PERSONS);
}

int security_viid::delete_persons(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_PERSONS);
}

int security_viid::query_person(const char* id, security_person_t& person) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_PERSONSS);
    if (ret == 0) {
        ret = msgFactory.parsePerson(body.c_str(), person);
    }
    return ret;
}

int security_viid::update_person(const char* id, const security_person_t& person) {
    string msg = security_message_factory::makePersonMessage(person);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_PERSONSS, "");
}

int security_viid::delete_person(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_PERSONSS, "");
}


int security_viid::add_faces(const security_faces_t& faces) {
    string msg = security_message_factory::makeFaceListMessage(faces);
    return add_list(msg, SECURITY_URL_PATH_VIID_FACES);
}

int security_viid::query_faces(const SecurityParams& params, security_faces_t& faces) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_FACES);
    if (ret == 0) {
        ret = msgFactory.parseFaceList(body.c_str(), faces);
    }
    return ret;
}

int security_viid::update_faces(const security_faces_t& faces) {
    string msg = security_message_factory::makeFaceListMessage(faces);
    return update_list(msg, SECURITY_URL_PATH_VIID_FACES);
}

int security_viid::delete_faces(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_FACES);
}

int security_viid::query_face(const char* id, security_face_t& face) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_FACESS);
    if (ret == 0) {
        ret = msgFactory.parseFace(body.c_str(), face);
    }
    return ret;
}

int security_viid::update_face(const char* id, const security_face_t& face) {
    string msg = security_message_factory::makeFaceMessage(face);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_FACESS, "");
}

int security_viid::delete_face(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_FACESS, "");
}


int security_viid::add_motorvehicles(const security_motorvehicles_t& motorvehicles) {
    string msg = security_message_factory::makeMotorVehicleListMessage(motorvehicles);
    return add_list(msg, SECURITY_URL_PATH_VIID_VIDEOSLICES);
}

int security_viid::query_motorvehicles(const SecurityParams& params, security_motorvehicles_t& motorvehicles) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_MOTORVEHIS);
    if (ret == 0) {
        ret = msgFactory.parseMotorVehicleList(body.c_str(), motorvehicles);
    }
    return ret;
}

int security_viid::update_motorvehicles(const security_motorvehicles_t& motorvehicles) {
    string msg = security_message_factory::makeMotorVehicleListMessage(motorvehicles);
    return update_list(msg, SECURITY_URL_PATH_VIID_MOTORVEHIS);
}

int security_viid::delete_motorvehicles(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_MOTORVEHIS);
}

int security_viid::query_motorvehicle(const char* id, security_motorvehicle_t& motorvehicle) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_MOTORVEHISS);
    if (ret == 0) {
        ret = msgFactory.parseMotorVehicle(body.c_str(), motorvehicle);
    }
    return ret;
}

int security_viid::update_motorvehicle(const char* id, const security_motorvehicle_t& motorvehicle) {
    string msg = security_message_factory::makeMotorVehicleMessage(motorvehicle);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_MOTORVEHISS, "");
}

int security_viid::delete_motorvehicle(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_MOTORVEHISS, "");
}


int security_viid::add_nonmotorvehicles(const security_nonmotorvehicles_t& nonmotorvehicles) {
    string msg = security_message_factory::makeNonMotorVehicleListMessage(nonmotorvehicles);
    return add_list(msg, SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
}

int security_viid::query_nonmotorvehicles(const SecurityParams& params, security_nonmotorvehicles_t& nonmotorvehicles) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
    if (ret == 0) {
        ret = msgFactory.parseNonMotorVehicleList(body.c_str(), nonmotorvehicles);
    }
    return ret;
}

int security_viid::update_nonmotorvehicles(const security_nonmotorvehicles_t& nonmotorvehicles) {
    string msg = security_message_factory::makeNonMotorVehicleListMessage(nonmotorvehicles);
    return update_list(msg, SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
}

int security_viid::delete_nonmotorvehicles(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_NONMOTORVEHIS);
}

int security_viid::query_nonmotorvehicle(const char* id, security_nonmotorvehicle_t& nonmotorvehicle) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_NONMOTORVEHISS);
    if (ret == 0) {
        ret = msgFactory.parseNonMotorVehicle(body.c_str(), nonmotorvehicle);
    }
    return ret;
}

int security_viid::update_nonmotorvehicle(const char* id, const security_nonmotorvehicle_t& nonmotorvehicle) {
    string msg = security_message_factory::makeNonMotorVehicleMessage(nonmotorvehicle);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_NONMOTORVEHISS, "");
}

int security_viid::delete_nonmotorvehicle(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_NONMOTORVEHISS, "");
}


int security_viid::add_things(const security_things_t& things) {
    string msg = security_message_factory::makeThingListMessage(things);
    return add_list(msg, SECURITY_URL_PATH_VIID_THINGS);
}

int security_viid::query_things(const SecurityParams& params, security_things_t& things) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_THINGS);
    if (ret == 0) {
        ret = msgFactory.parseThingList(body.c_str(), things);
    }
    return ret;
}

int security_viid::update_things(const security_things_t& things) {
    string msg = security_message_factory::makeThingListMessage(things);
    return update_list(msg, SECURITY_URL_PATH_VIID_THINGS);
}

int security_viid::delete_things(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_THINGS);
}

int security_viid::query_thing(const char* id, security_thing_t& thing) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_THINGSS);
    if (ret == 0) {
        ret = msgFactory.parseThing(body.c_str(), thing);
    }
    return ret;
}

int security_viid::update_thing(const char* id, const security_thing_t& thing) {
    string msg = security_message_factory::makeThingMessage(thing);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_THINGSS, "");
}

int security_viid::delete_thing(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_THINGSS, "");
}


int security_viid::add_scenes(const security_scenes_t& scenes) {
    string msg = security_message_factory::makeSceneListMessage(scenes);
    return add_list(msg, SECURITY_URL_PATH_VIID_SCENES);
}

int security_viid::query_scenes(const SecurityParams& params, security_scenes_t& scenes) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_SCENES);
    if (ret == 0) {
        ret = msgFactory.parseSceneList(body.c_str(), scenes);
    }
    return ret;
}

int security_viid::update_scenes(const security_scenes_t& scenes) {
    string msg = security_message_factory::makeSceneListMessage(scenes);
    return update_list(msg, SECURITY_URL_PATH_VIID_SCENES);
}

int security_viid::delete_scenes(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_SCENES);
}

int security_viid::query_scene(const char* id, security_scene_t& scene) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_SCENESS);
    if (ret == 0) {
        ret = msgFactory.parseScene(body.c_str(), scene);
    }
    return ret;
}

int security_viid::update_scene(const char* id, const security_scene_t& scene) {
    string msg = security_message_factory::makeSceneMessage(scene);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_SCENESS, "");
}

int security_viid::delete_scene(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_SCENESS, "");
}


int security_viid::add_cases(const security_cases_t& cases) {
    string msg = security_message_factory::makeCaseListMessage(cases);
    return add_list(msg, SECURITY_URL_PATH_VIID_CASES);
}

int security_viid::query_cases(const SecurityParams& params, security_cases_t& cases) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_CASES);
    if (ret == 0) {
        ret = msgFactory.parseCaseList(body.c_str(), cases);
    }
    return ret;
}

int security_viid::query_case(const char* id, security_case_t& caseo) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_CASESS);
    if (ret == 0) {
        ret = msgFactory.parseCase(body.c_str(), caseo);
    }
    return ret;
}

int security_viid::update_case(const char* id, const security_case_t& caseo) {
    string msg = security_message_factory::makeCaseMessage(caseo);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_CASESS);
}

int security_viid::delete_case(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_CASESS);
}

int security_viid::query_case_info(const char* id, security_caseinfo_t& info) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_CASESS, SECURITY_URL_PATH_S_INFO);
    if (ret == 0) {
        ret = msgFactory.parseCaseInfo(body.c_str(), info);
    }
    return ret;
}

int security_viid::update_case_info(const char* id, const security_caseinfo_t& info) {
    string msg = security_message_factory::makeCaseInfoMessage(info);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_CASESS, SECURITY_URL_PATH_S_INFO);
}

int security_viid::delete_case_info(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_CASESS, SECURITY_URL_PATH_S_INFO);
}


int security_viid::add_dispositions(const security_dispositions_t& dispositions) {
    string msg = security_message_factory::makeDispositionListMessage(dispositions);
    return add_list(msg, SECURITY_URL_PATH_VIID_DISPOSITIONS);
}

int security_viid::query_dispositions(const SecurityParams& params, security_dispositions_t& dispositions) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_DISPOSITIONS);
    if (ret == 0) {
        ret = msgFactory.parseDispositionList(body.c_str(), dispositions);
    }
    return ret;
}

int security_viid::update_dispositions(const security_dispositions_t& dispositions) {
    string msg = security_message_factory::makeDispositionListMessage(dispositions);
    return update_list(msg, SECURITY_URL_PATH_VIID_DISPOSITIONSS);
}

int security_viid::delete_dispositions(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_DISPOSITIONS);
}

int security_viid::query_disposition(const char* id, security_disposition_t& disposition) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_DISPOSITIONS);
    if (ret == 0) {
        ret = msgFactory.parseDisposition(body.c_str(), disposition);
    }
    return ret;
}

int security_viid::update_disposition(const char* id, const security_disposition_t& disposition) {
    string msg = security_message_factory::makeDispositionMessage(disposition);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_DISPOSITIONSS);
}

int security_viid::add_disposition_notifications(const security_disposition_notifications_t& notifications) {
    string msg = security_message_factory::makeDispositionNotificationListMessage(notifications);
    return add_list(msg, SECURITY_URL_PATH_VIID_DISPOSITIONNOTIFICATIONS);
}

int security_viid::query_disposition_notifications(const SecurityParams& params, security_disposition_notifications_t& notifications) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_DISPOSITIONNOTIFICATIONS);
    if (ret == 0) {
        ret = msgFactory.parseDispositionNotificationList(body.c_str(), notifications);
    }
    return ret;
}

int security_viid::delete_disposition_notifications(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_DISPOSITIONNOTIFICATIONS);
}

int security_viid::query_disposition_notification(const char* id, security_disposition_notification_t& notification) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_DISPOSITIONNOTIFICATIONSS);
    if (ret == 0) {
        ret = msgFactory.parseDispositionNotification(body.c_str(), notification);
    }
    return ret;
}

int security_viid::delete_disposition_notification(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_DISPOSITIONNOTIFICATIONS);
}


int security_viid::add_subscribes(const security_subscribes_t& subscribes) {
    string msg = security_message_factory::makeSubscribeListMessage(subscribes);
    return add_list(msg, SECURITY_URL_PATH_VIID_SUBSCRIBES);
}

int security_viid::query_subscribes(const SecurityParams& params, security_subscribes_t& subscribes) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_SUBSCRIBES);
    if (ret == 0) {
        ret = msgFactory.parseSubscribeList(body.c_str(), subscribes);
    }
    return ret;
}

int security_viid::update_subscribes(const security_subscribes_t& subscribes) {
    string msg = security_message_factory::makeSubscribeListMessage(subscribes);
    return update_list(msg, SECURITY_URL_PATH_VIID_SUBSCRIBES);
}

int security_viid::delete_subscribes(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_SUBSCRIBES);
}

int security_viid::update_subscribe(const char* id, const security_subscribe_t& subscribe) {
    string msg = security_message_factory::makeSubscribeMessage(subscribe);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_SUBSCRIBESS);
}

int security_viid::add_subscribe_notifications(const security_subscribe_notifications_t& notifications) {
    string msg = security_message_factory::makeSubscribeNotificationListMessage(notifications);
    return add_list(msg, SECURITY_URL_PATH_VIID_SUBSCRNOTI);
}

int security_viid::query_subscribe_notifications(const SecurityParams& params, security_subscribe_notifications_t& notifications) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_SUBSCRNOTI);
    if (ret == 0) {
        ret = msgFactory.parseSubscribeNotificationList(body.c_str(), notifications);
    }
    return ret;
}

int security_viid::delete_subscribe_notifications(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_SUBSCRIBES);
}


int security_viid::add_analysis_rules(const security_analysis_rules_t& rules) {
    string msg = security_message_factory::makeAnalysisRuleListMessage(rules);
    return add_list(msg, SECURITY_URL_PATH_VIID_ANALYSISRULES);
}

int security_viid::query_analysis_rules(const SecurityParams& params, security_analysis_rules_t& rules) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_ANALYSISRULES);
    if (ret == 0) {
        ret = msgFactory.parseAanalysisRuleList(body.c_str(), rules);
    }
    return ret;
}

int security_viid::update_analysis_rules(const security_analysis_rules_t& rules) {
    string msg = security_message_factory::makeAnalysisRuleListMessage(rules);
    return update_list(msg, SECURITY_URL_PATH_VIID_ANALYSISRULES);
}

int security_viid::delete_analysis_rules(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_ANALYSISRULES);
}

int security_viid::add_analysis_rule(const char* id, const security_analysis_rule_t& rule) {
    string msg = security_message_factory::makeAnalysisRuleMessage(rule);
    return add_object(id, msg, SECURITY_URL_PATH_VIID_ANALYSISRULESS, NULL);
}

int security_viid::query_analysis_rule(const char* id, security_analysis_rule_t& rule) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_ANALYSISRULESS);
    if (ret == 0) {
        ret = msgFactory.parseAanalysisRule(body.c_str(), rule);
    }
    return ret;
}

int security_viid::update_analysis_rule(const char* id, const security_analysis_rule_t& rule) {
    string msg = security_message_factory::makeAnalysisRuleMessage(rule);
    return update_object(id, msg, SECURITY_URL_PATH_VIID_ANALYSISRULESS);
}

int security_viid::delete_analysis_rule(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_ANALYSISRULESS);
}


int security_viid::add_video_labels(const security_videolabels_t& labels) {
    string msg = security_message_factory::makeVideoLabelListMessage(labels);
    return add_list(msg, SECURITY_URL_PATH_VIID_VIDEOLABELS);
}

int security_viid::query_video_labels(const SecurityParams& params, security_videolabels_t& labels) {
    string body;
    int ret = query_list(params, body, SECURITY_URL_PATH_VIID_VIDEOLABELS);
    if (ret == 0) {
        ret = msgFactory.parseVideoLabelList(body.c_str(), labels);
    }
    return ret;
}

int security_viid::update_video_labels(const security_videolabels_t& labels) {
    string msg = security_message_factory::makeVideoLabelListMessage(labels);
    return update_list(msg, SECURITY_URL_PATH_VIID_VIDEOLABELS);
}

int security_viid::delete_video_labels(const security_idlist_t& ids) {
    return delete_list(ids, SECURITY_URL_PATH_VIID_VIDEOLABELS);
}

int security_viid::add_video_label(const char* id, const security_videolabel_t& label) {
    string msg = security_message_factory::makeVideoLabelMessage(label);
    return add_object(id, msg, SECURITY_URL_PATH_VIID_VIDEOLABELSS, NULL);
}

int security_viid::query_video_label(const char* id, security_videolabel_t& label) {
    string body;
    int ret = query_object(id, body, SECURITY_URL_PATH_VIID_VIDEOLABELSS);
    if (ret == 0) {
        ret = msgFactory.parseVideoLabel(body.c_str(), label);
    }
    return ret;
}

int security_viid::update_video_label(const char* id, const security_videolabel_t& label) {
    string msg = security_message_factory::makeVideoLabelMessage(label);
    return update_list(msg, SECURITY_URL_PATH_VIID_VIDEOLABELSS);
}

int security_viid::delete_video_label(const char* id) {
    return delete_object(id, SECURITY_URL_PATH_VIID_VIDEOLABELSS);
}



int security_viid::add_list(const string& msg, const char* viidUri) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (msg.empty()) {
        printf("msg invalid\n");
        return -1;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Post(viidUri, headers, msg, CONTENT_TYPE)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("add %s failed %d\n", viidUri, res->status);
            return -1;
        }
        lastTime = gettime_ms();
        security_response_statuss_t statuss;
        ret = msgFactory.parseResponseStatusList(res->body.c_str(), statuss);
        if (0 != ret) {
            printf("parseResponseStatusList failed\n");
            return -1;
        }
    }
    else {
        auto err = res.error();
        printf("add %s failed %d\n", viidUri, err);
        return -1;
    }
    printf("add %s success\n", viidUri);
    return 0;
}

int security_viid::add_object(const char* id, const string& msg, const char* viidUri, const char* otherUri) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("id invalid.\n");
        return -1;
    }
    if (msg.empty()) {
        printf("msg invalid.\n");
        return -1;
    }

    string url(viidUri);
    url += id;
    if (otherUri != NULL) {
        url += otherUri;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Post(url.c_str(), headers, msg, CONTENT_TYPE)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("add %s failed %d\n", url.c_str(), res->status);
            return -1;
        }
        lastTime = gettime_ms();
        if (otherUri == NULL) {
            security_response_statuss_t statuss;
            ret = msgFactory.parseResponseStatusList(res->body.c_str(), statuss);
            if (0 != ret) {
                printf("parseResponseStatusList failed\n");
                return -1;
            }
        }
        else {
            security_response_status_t status;
            ret = msgFactory.parseResponseStatus(res->body.c_str(), status);
            if (0 != ret) {
                printf("parseResponseStatus failed\n");
                return -1;
            }
        }
    }
    else {
        auto err = res.error();
        printf("add %s failed %d\n", url.c_str(), err);
        return -1;
    }
    printf("add %s success\n", url.c_str());
    return 0;
}

int security_viid::query_list(const SecurityParams& params, string& body, const char* viidUri) {
    if (!registered) {
        return -1;
    }

    string url(viidUri);
    if (!params.empty()) {
        url += "?";
        url += detail::params_to_query_str(params);
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Get(url.c_str(), headers)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("get %s failed %d\n", url.c_str(), res->status);
            return -1;
        }
        lastTime = gettime_ms();
        body = res->body;
    }
    else {
        auto err = res.error();
        printf("get %s failed %d\n", url.c_str(), err);
        return -1;
    }
    printf("get %s success\n", url.c_str());
    return 0;
}

int security_viid::query_object(const char* id, string& body, const char* viidUri, const char* otherUri) {
    if (!registered) {
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("id invalid.\n");
        return -1;
    }

    string url(viidUri);
    url += id;
    if (otherUri != NULL) {
        url += otherUri;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Get(url.c_str(), headers)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("get %s failed %d\n", url.c_str(), res->status);
            return -1;
        }
        lastTime = gettime_ms();
        body = res->body;
    }
    else {
        auto err = res.error();
        printf("get %s failed %d\n", url.c_str(), err);
        return -1;
    }
    printf("get %s success\n", url.c_str());
    return 0;
}

int security_viid::update_list(const string& msg, const char* viidUri) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (msg.empty()) {
        printf("msg invalid\n");
        return -1;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Put(viidUri, headers, msg, CONTENT_TYPE)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("update %s failed %d\n", viidUri, res->status);
            return -1;
        }
        lastTime = gettime_ms();
        security_response_statuss_t statuss;
        ret = msgFactory.parseResponseStatusList(res->body.c_str(), statuss);
        if (0 != ret) {
            printf("parseResponseStatusList failed\n");
            return -1;
        }
    }
    else {
        auto err = res.error();
        printf("update %s failed %d\n", viidUri, err);
        return -1;
    }
    printf("update %s success\n", viidUri);
    return 0;
}

int security_viid::update_object(const char* id, const string& msg, const char* viidUri, const char* otherUri) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("id invalid.\n");
        return -1;
    }
    if (msg.empty()) {
        printf("msg invalid.\n");
        return -1;
    }

    string url(viidUri);
    url += id;
    if (otherUri != NULL) {
        url += otherUri;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Put(url.c_str(), headers, msg, CONTENT_TYPE)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("update %s failed %d\n", url.c_str(), res->status);
            return -1;
        }
        lastTime = gettime_ms();
        if (otherUri == NULL) {
            security_response_statuss_t statuss;
            ret = msgFactory.parseResponseStatusList(res->body.c_str(), statuss);
            if (0 != ret) {
                printf("parseResponseStatusList failed\n");
                return -1;
            }
        }
        else {
            security_response_status_t status;
            ret = msgFactory.parseResponseStatus(res->body.c_str(), status);
            if (0 != ret) {
                printf("parseResponseStatus failed\n");
                return -1;
            }
        }
    }
    else {
        auto err = res.error();
        printf("update %s failed %d\n", url.c_str(), err);
        return -1;
    }
    printf("update %s success\n", url.c_str());
    return 0;
}

int security_viid::delete_list(const security_idlist_t& ids, const char* viidUri) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (!ids.empty()) {
        printf("ids invalid.\n");
        return -1;
    }

    string url(viidUri);
    url += "?IDList=";

    int i = 0;
    for (auto id : ids) {
        if (i++ != 0) {
            url += ",";
        }
        url += id;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Delete(url.c_str(), headers)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("delete %s failed %d\n", url.c_str(), res->status);
            return -1;
        }
        lastTime = gettime_ms();
        security_response_statuss_t statuss;
        ret = msgFactory.parseResponseStatusList(res->body.c_str(), statuss);
        if (0 != ret) {
            printf("parseResponseStatuss failed\n");
            return -1;
        }
    }
    else {
        auto err = res.error();
        printf("delete %s failed %d\n", url.c_str(), err);
        return -1;
    }
    printf("delete %s success\n", url.c_str());
    return 0;
}

int security_viid::delete_object(const char* id, const char* viidUri, const char* otherUri) {
    int ret;
    if (!registered) {
        return -1;
    }
    if (!id || strlen(id) < 1) {
        printf("id invalid.\n");
        return -1;
    }

    string url(viidUri);
    url += id;
    if (otherUri != NULL) {
        url += otherUri;
    }

    Headers headers = get_common_req_header(this->deviceId);
    Client cli(ip, port);
    if (auto res = cli.Delete(url.c_str(), headers)) {
        printf("response: %s, %d\n", res->body.c_str(), res->status);
        if (SECURITY_REST_HTTP_RESPONSE_200 != res->status) {
            printf("delete %s failed %d\n", url.c_str(), res->status);
            return -1;
        }
        lastTime = gettime_ms();
        if (otherUri == NULL) {
            security_response_statuss_t statuss;
            ret = msgFactory.parseResponseStatusList(res->body.c_str(), statuss);
            if (0 != ret) {
                printf("parseResponseStatusList failed\n");
                return -1;
            }
        }
        else {
            security_response_status_t status;
            ret = msgFactory.parseResponseStatus(res->body.c_str(), status);
            if (0 != ret) {
                printf("parseResponseStatus failed\n");
                return -1;
            }
        }
    }
    else {
        auto err = res.error();
        printf("delete %s failed %d\n", url.c_str(), err);
        return -1;
    }
    printf("delete %s success\n", url.c_str());
    return 0;
}
