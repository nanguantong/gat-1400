/**
 * @File     gat1400_message_factory.h
 * @brief    
 * @DateTime 2018/2/4 10:21:23
 * @Author   Nanuns
 */
#ifndef __GAT1400_MESSAGE_FACTORY_H_
#define __GAT1400_MESSAGE_FACTORY_H_

#include "gat1400_types.h"

/**
 * @Class    security_message_factory
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
class security_message_factory {
public:
    /**
     * @Method   makeRegisterMessage
     * @Brief    {"RegisterObject ":{"DeviceID":"33010299011190000253"}}
     * @DateTime 2018-08-04T12:15:12+0800
     * @Modify   2018-08-04T12:15:12+0800
     * @Author   Nanuns
     * @param    deviceId [description]
     * @return   [description]
     */
    static SecurityString makeRegisterMessage(const char* deviceId);
    /**
     * @Method   makeUnregisterMessage
     * @Brief    {"UnRegisterObject ":{"DeviceID":"33010299011190000253"}}
     * @DateTime 2018-08-04T12:15:12+0800
     * @Modify   2018-08-04T12:15:12+0800
     * @Author   Nanuns
     * @param    deviceId [description]
     * @return   [description]
     */
    static SecurityString makeUnregisterMessage(const char* deviceId);
    /**
     * @Method   makeKeepaliveMessage
     * @Brief    {"KeepaliveObject ":{"DeviceID":"33010299011190000253"}}
     * @DateTime 2018-08-04T12:15:12+0800
     * @Modify   2018-08-04T12:15:12+0800
     * @Author   Nanuns
     * @param    deviceId [description]
     * @return   [description]
     */
    static SecurityString makeKeepaliveMessage(const char* deviceId);
    static SecurityString makeTimeMessage(const security_system_time_t& time);
    static SecurityString makeAPEListMessage(const security_apes_t& apes);
    static SecurityString makeVideoSliceListMessage(const security_videoslices_t& slices);
    static SecurityString makeVideoSliceMessage(const security_videoslice_t& slice);
    static SecurityString makeVideoSliceInfoListMessage(const security_videoslice_infos_t& infos);
    static SecurityString makeVideoSliceInfoMessage(const security_videoslice_info_t& info);
    static SecurityString makeImageListMessage(const security_images_t& images);
    static SecurityString makeImageMessage(const security_image_t& image);
    static SecurityString makeImageInfoMessage(const security_image_info_t& info);
    static SecurityString makeFileListMessage(const security_files_t& files);
    static SecurityString makeFileMessage(const security_file_t& file);
    static SecurityString makeFileInfoMessage(const security_file_info_t& info);
    static SecurityString makePersonListMessage(const security_persons_t& persons);
    static SecurityString makePersonMessage(const security_person_t& person);
    static SecurityString makeFaceListMessage(const security_faces_t& faces);
    static SecurityString makeFaceMessage(const security_face_t& face);
    static SecurityString makeMotorVehicleListMessage(const security_motorvehicles_t& motorVehicles);
    static SecurityString makeMotorVehicleMessage(const security_motorvehicle_t& motorVehicle);
    static SecurityString makeNonMotorVehicleListMessage(const security_nonmotorvehicles_t& nonmotorVehicles);
    static SecurityString makeNonMotorVehicleMessage(const security_nonmotorvehicle_t& nonmotorVehicle);
    static SecurityString makeThingListMessage(const security_things_t& things);
    static SecurityString makeThingMessage(const security_thing_t& thing);
    static SecurityString makeSceneListMessage(const security_scenes_t& scenes);
    static SecurityString makeSceneMessage(const security_scene_t& scene);
    static SecurityString makeCaseListMessage(const security_cases_t& cases);
    static SecurityString makeCaseMessage(const security_case_t& caseo);
    static SecurityString makeCaseInfoMessage(const security_caseinfo_t& info);
    static SecurityString makeDispositionMessage(const security_disposition_t& disp);
    static SecurityString makeDispositionListMessage(const security_dispositions_t& disps);
    static SecurityString makeDispositionNotificationMessage(const security_disposition_notification_t& notification);
    static SecurityString makeDispositionNotificationListMessage(const security_disposition_notifications_t& notifications);
    static SecurityString makeSubscribeListMessage(const security_subscribes_t& subscribes);
    static SecurityString makeSubscribeMessage(const security_subscribe_t& subscribe);
    static SecurityString makeSubscribeNotificationListMessage(const security_subscribe_notifications_t& notifications);
    static SecurityString makeAnalysisRuleListMessage(const security_analysis_rules_t& rules);
    static SecurityString makeAnalysisRuleMessage(const security_analysis_rule_t& rule);
    static SecurityString makeVideoLabelListMessage(const security_videolabels_t& labels);
    static SecurityString makeVideoLabelMessage(const security_videolabel_t& label);


    static int parseResponseStatusList(const char* body, security_response_statuss_t& statuss);
    static int parseResponseStatus(const char* body, security_response_status_t& status);
    static int parseSystemTime(const char* body, security_system_time_t& time);

    static int parseApeList(const char* body, security_apes_t& apes);
    static int parseApsList(const char* body, security_apss_t& apss);

    static int parseTollgateList(const char* body, security_tollgates_t& tatollgates);
    static int parseLaneList(const char* body, security_lanes_t& lanes);

    static int parseVideoSliceList(const char* body, security_videoslices_t& slices);
    static int parseVideoSlice(const char* body, security_videoslice_t& slice);
    static int parseVideoSliceInfo(const char* body, security_videoslice_info_t& info);

    static int parseFileList(const char* body, security_files_t& files);
    static int parseFile(const char* body, security_file_t& file);
    static int parseFileInfo(const char* body, security_file_info_t& info);

    static int parsePersonList(const char* body, security_persons_t& persons);
    static int parsePerson(const char* body, security_person_t& person);

    static int parseThingList(const char* body, security_things_t& things);
    static int parseThing(const char* body, security_thing_t& thing);

    static int parseSceneList(const char* body, security_scenes_t& scenes);
    static int parseScene(const char* body, security_scene_t& scene);

    static int parseCaseList(const char* body, security_cases_t& cases);
    static int parseCase(const char* body, security_case_t& caseo);
    static int parseCaseInfo(const char* body, security_caseinfo_t& info);

    static int parseImageList(const char* body, security_images_t& images);
    static int parseImage(const char* body, security_image_t& image);
    static int parseImageInfo(const char* body, security_image_info_t& info);

    static int parseDispositionList(const char* body, security_dispositions_t& dispositions);
    static int parseDisposition(const char* body, security_disposition_t& disposition);
    static int parseDispositionNotificationList(const char* body, security_disposition_notifications_t& notifications);
    static int parseDispositionNotification(const char* body, security_disposition_notification_t& notification);

    static int parseSubscribeList(const char* body, security_subscribes_t& subscribes);
    static int parseSubscribe(const char* body, security_subscribe_t& subscribe);

    static int parseSubscribeNotificationList(const char* body, security_subscribe_notifications_t& notifications);
    static int parseSubscribeNotification(const char* body, security_subscribe_notification_t& notification);

    static int parseAanalysisRuleList(const char* body, security_analysis_rules_t& rules);
    static int parseAanalysisRule(const char* body, security_analysis_rule_t& rule);

    static int parseVideoLabelList(const char* body, security_videolabels_t& labels);
    static int parseVideoLabel(const char* body, security_videolabel_t& label);

    static int parseFaceList(const char* body, security_faces_t& faces);
    static int parseFace(const char* body, security_face_t& face);

    static int parseMotorVehicleList(const char* body, security_motorvehicles_t& motorvehicles);
    static int parseMotorVehicle(const char* body, security_motorvehicle_t& motorvehicle);

    static int parseNonMotorVehicleList(const char* body, security_nonmotorvehicles_t& nonmotorvehicles);
    static int parseNonMotorVehicle(const char* body, security_nonmotorvehicle_t& nonmotorvehicle);
};


#endif
