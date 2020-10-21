/**
 * @File     gat1400_viid.h
 * @brief
 * @DateTime 2018/2/4 10:21:23
 * @Author   Nanuns
 */
#ifndef __GAT1400_VIID_H_
#define __GAT1400_VIID_H_

#include "gat1400_message_factory.h"

using namespace std;

/**
 * @Class    security_viid
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
class security_viid {
public:
    /**
     * @Method   sys_register
     * @Brief    注册失败时，应延迟300s内的随机时间后重新注册。注册成功后，在90s内未交互信息则进行心跳保活
     * @DateTime 2018-08-04T12:15:07+0800
     * @Modify   2018-08-04T12:15:07+0800
     * @Author   Nanuns
     * @param    ip [description]
     * @param    port [description]
     * @param    deviceId [description]
     * @param    username [description]
     * @param    password [description]
     * @return   [description]
     */
    int    sys_register(const char* ip, int port, const char* deviceId, const char* username, const char* password);
    /**
     * @Method   sys_unregister
     * @Brief
     * @DateTime 2018-08-04T12:42:02+0800
     * @Modify   2018-08-04T12:42:02+0800
     * @Author   Nanuns
     * @return   [description]
     */
    int    sys_unregister();
    /**
     * @Method   sys_keepalive
     * @Brief    注册成功后，在有效期内（一般为5分钟），如果没有接收到新的请求，注册信息将会失效，
     *           下次访问将需要重新注册；当然任何形式的成功请求，都能触发保活机制，重置有效期
     * @DateTime 2018-08-04T12:54:41+0800
     * @Modify   2018-08-04T12:54:41+0800
     * @Author   Nanuns
     * @return   [description]
     */
    int    sys_keepalive();
    int    sys_synctime(security_system_time_t& time);

    bool   is_registered() { return registered; }

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   query_apes
     * @Brief    查询采集设备
     * @DateTime 2018-08-04T14:15:03+0800
     * @Modify   2018-08-04T14:15:03+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    apes [description]
     * @return   [description]
     */
    int    query_apes(const SecurityParams& params, security_apes_t& apes);
    /**
     * @Method   update_apes
     * @Brief    批量更新采集设备,用于更新采集设备的口令,以实现动态口令管理
     * @DateTime 2018-08-04T14:21:52+0800
     * @Modify   2018-08-04T14:21:52+0800
     * @Author   Nanuns
     * @param    apes [description]
     * @return   [description]
     */
    int    update_apes(const security_apes_t& apes);
    /**
     * @Method   query_apss
     * @Brief    批量查询采集系统
     * @DateTime 2018-08-06T10:36:45+0800
     * @Modify   2018-08-06T10:36:45+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    apss [description]
     * @return   [description]
     */
    int    query_apss(const SecurityParams& params, security_apss_t& apss);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   query_tollgates
     * @Brief    批量查询视频卡口
     * @DateTime 2018-08-06T10:56:35+0800
     * @Modify   2018-08-06T10:56:35+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    tatollgates [description]
     * @return   [description]
     */
    int    query_tollgates(const SecurityParams& params, security_tollgates_t& tatollgates);
    /**
     * @Method   query_lanes
     * @Brief    批量查询车道
     * @DateTime 2018-08-06T10:56:47+0800
     * @Modify   2018-08-06T10:56:47+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    lanes [description]
     * @return   [description]
     */
    int    query_lanes(const SecurityParams& params, security_lanes_t& lanes);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_video_slices
     * @Brief    批量添加视频片段
     * @DateTime 2018-08-06T11:29:09+0800
     * @Modify   2018-08-06T11:29:09+0800
     * @Author   Nanuns
     * @param    slice [description]
     * @return   [description]
     */
    int    add_video_slices(const security_videoslices_t& slices);
    /**
      * @Method   query_video_slices
      * @Brief    批量查询视频片段
      * @DateTime 2018-08-06T11:28:58+0800
      * @Modify   2018-08-06T11:28:58+0800
      * @Author   Nanuns
      * @param    params [description]
      * @param    slices [description]
      * @return   [description]
      */
    int    query_video_slices(const SecurityParams& params, security_videoslices_t& slices);
    /**
     * @Method   query_video_slice
     * @Brief    单个查询视频片段
     * @DateTime 2018-08-06T11:31:57+0800
     * @Modify   2018-08-06T11:31:57+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    slice [description]
     * @return   [description]
     */
    int    query_video_slice(const char* id, security_videoslice_t& slice);
    /**
     * @Method   update_video_slice
     * @Brief    单个更新视频片段
     * @DateTime 2018-08-06T11:34:16+0800
     * @Modify   2018-08-06T11:34:16+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    slice [description]
     * @return   [description]
     */
    int    update_video_slice(const char* id, const security_videoslice_t& slice);
    /**
     * @Method   delete_video_slice
     * @Brief    单个删除视频片段
     * @DateTime 2018-08-06T11:36:00+0800
     * @Modify   2018-08-06T11:36:00+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_video_slice(const char* id);

    /**
     * @Method   query_video_slice_info
     * @Brief    单个查询视频片段对象信息
     * @DateTime 2018-08-06T11:43:35+0800
     * @Modify   2018-08-06T11:43:35+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    info
     * @return   [description]
     */
    int    query_video_slice_info(const char* id, security_videoslice_info_t& info);
    /**
     * @Method   update_video_slice_info
     * @Brief    单个更新视频片段对象信息
     * @DateTime 2018-08-06T11:45:46+0800
     * @Modify   2018-08-06T11:45:46+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    info [description]
     * @return   [description]
     */
    int    update_video_slice_info(const char* id, const security_videoslice_info_t& info);
    /**
     * @Method   delete_video_slice_info
     * @Brief    单个删除视频片段对象信息
     * @DateTime 2018-08-06T11:45:57+0800
     * @Modify   2018-08-06T11:45:57+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_video_slice_info(const char* id);
    /**
     * @Method   add_video_slice_data
     * @Brief    单个添加视频片段对象数据
     * @DateTime 2018-08-06T11:45:46+0800
     * @Modify   2018-08-06T11:45:46+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    buf [description]
     * @return   [description]
     */
    int    add_video_slice_data(const char* id, const char* buf);
    /**
     * @Method   query_video_slice_data
     * @Brief    单个查询视频片段对象数据
     * @DateTime 2018-08-06T11:43:35+0800
     * @Modify   2018-08-06T11:43:35+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    buff base64 binary data
     * @return   [description]
     */
    int    query_video_slice_data(const char* id, string& buf);
    /**
     * @Method   delete_videodata
     * @Brief    单个删除视频片段对象数据
     * @DateTime 2018-08-06T11:45:57+0800
     * @Modify   2018-08-06T11:45:57+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_video_slice_data(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_images
     * @Brief    批量添加图像
     * @DateTime 2018-08-06T12:27:44+0800
     * @Modify   2018-08-06T12:27:44+0800
     * @Author   Nanuns
     * @param    images [description]
     * @return   [description]
     */
    int    add_images(const security_images_t& images);
    /**
     * @Method   query_images
     * @Brief    批量查询图像
     * @DateTime 2018-08-06T12:06:58+0800
     * @Modify   2018-08-06T12:06:58+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    images [description]
     * @return   [description]
     */
    int    query_images(const SecurityParams& params, security_images_t& images);
    /**
     * @Method   query_image
     * @Brief    单个查询图像
     * @DateTime 2018-08-06T14:29:40+0800
     * @Modify   2018-08-06T14:29:40+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    image [description]
     * @return   [description]
     */
    int    query_image(const char* id, security_image_t& image);
    /**
     * @Method   update_image
     * @Brief    单个更新图像
     * @DateTime 2018-08-06T14:32:43+0800
     * @Modify   2018-08-06T14:32:43+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    image [description]
     * @return   [description]
     */
    int    update_image(const char* id, const security_image_t& image);
    /**
     * @Method   delete_image
     * @Brief    单个删除图像
     * @DateTime 2018-08-06T14:34:21+0800
     * @Modify   2018-08-06T14:34:21+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_image(const char* id);
    /**
     * @Method   query_image_info
     * @Brief    单个查询图像对象信息
     * @DateTime 2018-08-06T14:38:26+0800
     * @Modify   2018-08-06T14:38:26+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    info [description]
     * @return   [description]
     */
    int    query_image_info(const char* id, security_image_info_t& info);
    /**
     * @Method   update_image_info
     * @Brief    单个更新图像对象信息
     * @DateTime 2018-08-06T15:16:36+0800
     * @Modify   2018-08-06T15:16:36+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    info [description]
     * @return   [description]
     */
    int    update_image_info(const char* id, const security_image_info_t& info);
    /**
     * @Method   delete_image_info
     * @Brief    单个删除图像对象信息
     * @DateTime 2018-08-06T15:17:14+0800
     * @Modify   2018-08-06T15:17:14+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_image_info(const char* id);
    /**
     * @Method   add_image_data
     * @Brief    单个添加图像对象数据
     * @DateTime 2018-08-06T15:23:56+0800
     * @Modify   2018-08-06T15:23:56+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    buf [description]
     * @return   [description]
     */
    int    add_image_data(const char* id, const char* buf);
    /**
     * @Method   query_image_data
     * @Brief    单个查询图像对象数据
     * @DateTime 2018-08-06T15:20:13+0800
     * @Modify   2018-08-06T15:20:13+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    buf data got base64 binary of image
     * @return   [description]
     */
    int    query_image_data(const char* id, string& buf);
    /**
     * @Method   delete_image_data
     * @Brief    单个删除图像对象数据
     * @DateTime 2018-08-06T15:25:28+0800
     * @Modify   2018-08-06T15:25:28+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_image_data(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_files
     * @Brief    批量添加文件
     * @DateTime 2018-08-06T15:51:02+0800
     * @Modify   2018-08-06T15:51:02+0800
     * @Author   Nanuns
     * @param    files [description]
     * @return   [description]
     */
    int    add_files(const security_files_t& files);
    /**
     * @Method   query_files
     * @Brief    批量查询文件
     * @DateTime 2018-08-06T15:36:28+0800
     * @Modify   2018-08-06T15:36:28+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    files [description]
     * @return   [description]
     */
    int    query_files(const SecurityParams& params, security_files_t& files);
    /**
     * @Method   query_file
     * @Brief    单个查询文件
     * @DateTime 2018-08-06T15:54:59+0800
     * @Modify   2018-08-06T15:54:59+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    file [description]
     * @return   [description]
     */
    int    query_file(const char* id, security_file_t& file);
    /**
     * @Method   update_file
     * @Brief    单个更新文件
     * @DateTime 2018-08-06T16:07:35+0800
     * @Modify   2018-08-06T16:07:35+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    file [description]
     * @return   [description]
     */
    int    update_file(const char* id, const security_file_t& file);
    /**
     * @Method   delete_file
     * @Brief    单个删除文件
     * @DateTime 2018-08-06T16:09:19+0800
     * @Modify   2018-08-06T16:09:19+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_file(const char* id);
    /**
     * @Method   query_file_info
     * @Brief    单个查询文件对象信息
     * @DateTime 2018-08-06T16:12:58+0800
     * @Modify   2018-08-06T16:12:58+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    query_file_info(const char* id, security_file_info_t& info);
    /**
     * @Method   update_fileinfo
     * @Brief    单个更新文件对象信息
     * @DateTime 2018-08-06T16:21:51+0800
     * @Modify   2018-08-06T16:21:51+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    info [description]
     * @return   [description]
     */
    int    update_file_info(const char* id, const security_file_info_t& info);
    /**
     * @Method   delete_fileinfo
     * @Brief    单个删除文件对象信息
     * @DateTime 2018-08-06T16:23:00+0800
     * @Modify   2018-08-06T16:23:00+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_file_info(const char* id);
    /**
     * @Method   add_filedata
     * @Brief    单个添加文件对象数据
     * @DateTime 2018-08-06T16:30:45+0800
     * @Modify   2018-08-06T16:30:45+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    buf base64 binary of file
     * @return   [description]
     */
    int    add_file_data(const char* id, const char* buf);
    /**
     * @Method   query_filedata
     * @Brief    单个查询文件对象数据
     * @DateTime 2018-08-06T16:29:23+0800
     * @Modify   2018-08-06T16:29:23+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    buf base64 binary of image
     * @return   [description]
     */
    int    query_file_data(const char* id, string& buf);
    /**
     * @Method   delete_filedata
     * @Brief    单个删除文件对象数据
     * @DateTime 2018-08-06T16:31:50+0800
     * @Modify   2018-08-06T16:31:50+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_file_data(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
   /**
     * @Method   add_persons
     * @Brief    批量添加人员
     * @DateTime 2018-08-06T16:44:26+0800
     * @Modify   2018-08-06T16:44:26+0800
     * @Author   Nanuns
     * @param    personList [description]
     * @return   [description]
     */
    int    add_persons(const security_persons_t& persons);
    /**
     * @Method   query_persons
     * @Brief    批量查询人员
     * @DateTime 2018-08-06T16:35:38+0800
     * @Modify   2018-08-06T16:35:38+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    persons [description]
     * @return   [description]
     */
    int    query_persons(const SecurityParams& params, security_persons_t& persons);
    /**
     * @Method   update_persons
     * @Brief    批量更新人员
     * @DateTime 2018-08-06T17:02:55+0800
     * @Modify   2018-08-06T17:02:55+0800
     * @Author   Nanuns
     * @param    personList [description]
     * @return   [description]
     */
    int    update_persons(const security_persons_t& persons);
    /**
     * @Method   delete_persons
     * @Brief    批量删除人员
     * @DateTime 2018-08-06T16:52:39+0800
     * @Modify   2018-08-06T16:52:39+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_persons(const security_idlist_t& ids);
    /**
     * @Method   query_person
     * @Brief    单个查询人员
     * @DateTime 2018-08-06T17:00:10+0800
     * @Modify   2018-08-06T17:00:10+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    person [description]
     * @return   [description]
     */
    int    query_person(const char* id, security_person_t& person);
    /**
     * @Method   update_person
     * @Brief    单个更新人员
     * @DateTime 2018-08-06T17:05:30+0800
     * @Modify   2018-08-06T17:05:30+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    person [description]
     * @return   [description]
     */
    int    update_person(const char* id, const security_person_t& person);
    /**
     * @Method   delete_person
     * @Brief    单个删除人员
     * @DateTime 2018-08-06T17:06:35+0800
     * @Modify   2018-08-06T17:06:35+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_person(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_faces
     * @Brief    批量添加人脸
     * @DateTime 2018-08-08T11:12:26+0800
     * @Modify   2018-08-08T11:12:26+0800
     * @Author   Nanuns
     * @param    faces [description]
     * @return   [description]
     */
    int    add_faces(const security_faces_t& faces);
    /**
     * @Method   query_faces
     * @Brief    批量查询人脸
     * @DateTime 2018-08-08T10:46:44+0800
     * @Modify   2018-08-08T10:46:44+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    faces [description]
     * @return   [description]
     */
    int    query_faces(const SecurityParams& params, security_faces_t& faces);
    /**
     * @Method   update_faces
     * @Brief    批量更新人脸
     * @DateTime 2018-08-08T10:47:39+0800
     * @Modify   2018-08-08T10:47:39+0800
     * @Author   Nanuns
     * @param    faces [description]
     * @return   [description]
     */
    int    update_faces(const security_faces_t& faces);
    /**
     * @Method   delete_faces
     * @Brief    批量删除人脸
     * @DateTime 2018-08-08T10:49:53+0800
     * @Modify   2018-08-08T10:49:53+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_faces(const security_idlist_t& ids);
    /**
     * @Method   query_face
     * @Brief    单个查询人脸
     * @DateTime 2018-08-08T10:54:51+0800
     * @Modify   2018-08-08T10:54:51+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    query_face(const char* id, security_face_t& face);
    /**
     * @Method   update_face
     * @Brief    单个更新人脸
     * @DateTime 2018-08-08T10:57:35+0800
     * @Modify   2018-08-08T10:57:35+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    face [description]
     * @return   [description]
     */
    int    update_face(const char* id, const security_face_t& face);
    /**
     * @Method   delete_face
     * @Brief    单个删除人脸
     * @DateTime 2018-08-08T11:01:15+0800
     * @Modify   2018-08-08T11:01:15+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_face(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
     /**
      * @Method   add_motorvehicles
      * @Brief    批量添加机动车
      * @DateTime 2018-08-08T11:12:26+0800
      * @Modify   2018-08-08T11:12:26+0800
      * @Author   Nanuns
      * @param    motorvehicles [description]
      * @return   [description]
      */
    int    add_motorvehicles(const security_motorvehicles_t& motorvehicles);
    /**
     * @Method   query_motorvehiclies
     * @Brief    批量查询机动车
     * @DateTime 2018-08-08T11:09:18+0800
     * @Modify   2018-08-08T11:09:18+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    motorvehicles [description]
     * @return   [description]
     */
    int    query_motorvehicles(const SecurityParams& params, security_motorvehicles_t& motorvehicles);
    /**
     * @Method   update_motorvehicles
     * @Brief    批量更新机动车
     * @DateTime 2018-08-08T11:13:01+0800
     * @Modify   2018-08-08T11:13:01+0800
     * @Author   Nanuns
     * @param    motorvehicles [description]
     * @return   [description]
     */
    int    update_motorvehicles(const security_motorvehicles_t& motorvehicles);
    /**
     * @Method   delete_motorvehicles
     * @Brief    批量删除机动车
     * @DateTime 2018-08-08T11:16:50+0800
     * @Modify   2018-08-08T11:16:50+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_motorvehicles(const security_idlist_t& ids);
    /**
     * @Method   query_motorvehicle
     * @Brief    单个查询机动车
     * @DateTime 2018-08-08T11:20:54+0800
     * @Modify   2018-08-08T11:20:54+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    motorvehicle [description]
     * @return   [description]
     */
    int    query_motorvehicle(const char* id, security_motorvehicle_t& motorvehicle);
    /**
     * @Method   update_motorvehicle
     * @Brief    单个更新机动车
     * @DateTime 2018-08-08T11:23:40+0800
     * @Modify   2018-08-08T11:23:40+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    motorvehicle [description]
     * @return   [description]
     */
    int    update_motorvehicle(const char* id, const security_motorvehicle_t& motorvehicle);
    /**
     * @Method   delete_motorvehicles
     * @Brief    单个删除机动车
     * @DateTime 2018-08-08T11:29:11+0800
     * @Modify   2018-08-08T11:29:11+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_motorvehicle(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_nonmotorvehicles
     * @Brief    批量添加非机动车
     * @DateTime 2018-08-08T11:35:11+0800
     * @Modify   2018-08-08T11:35:11+0800
     * @Author   Nanuns
     * @param    nonmotorvehicles [description]
     * @return   [description]
     */
    int    add_nonmotorvehicles(const security_nonmotorvehicles_t& nonmotorvehicles);
    /**
     * @Method   query_nonmotorvehicles
     * @Brief    批量查询非机动车
     * @DateTime 2018-08-08T11:33:17+0800
     * @Modify   2018-08-08T11:33:17+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    nonmotorvehicles [description]
     * @return   [description]
     */
    int    query_nonmotorvehicles(const SecurityParams& params, security_nonmotorvehicles_t& nonmotorvehicles);
    /**
     * @Method   update_nonmotorvehicles
     * @Brief    批量更新非机动车
     * @DateTime 2018-08-08T11:36:30+0800
     * @Modify   2018-08-08T11:36:30+0800
     * @Author   Nanuns
     * @param    nonmotorvehicles [description]
     * @return   [description]
     */
    int    update_nonmotorvehicles(const security_nonmotorvehicles_t& nonmotorvehicles);
    /**
     * @Method   delete_nonmotorvehicles
     * @Brief    批量删除非机动车
     * @DateTime 2018-08-08T11:37:04+0800
     * @Modify   2018-08-08T11:37:04+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_nonmotorvehicles(const security_idlist_t& ids);
    /**
     * @Method   query_nonmotorvehicle
     * @Brief    单个查询非机动车
     * @DateTime 2018-08-08T11:37:45+0800
     * @Modify   2018-08-08T11:37:45+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    nonmotorvehicle [description]
     * @return   [description]
     */
    int    query_nonmotorvehicle(const char* id, security_nonmotorvehicle_t& nonmotorvehicle);
    /**
     * @Method   update_nonmotorvehicle
     * @Brief    单个更新非机动车
     * @DateTime 2018-08-08T11:23:40+0800
     * @Modify   2018-08-08T11:23:40+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    nonmotorvehicle [description]
     * @return   [description]
     */
    int    update_nonmotorvehicle(const char* id, const security_nonmotorvehicle_t& nonmotorvehicle);
    /**
     * @Method   delete_nonmotorvehicle
     * @Brief    单个删除非机动车
     * @DateTime 2018-08-08T11:39:56+0800
     * @Modify   2018-08-08T11:39:56+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_nonmotorvehicle(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_things
     * @Brief    批量添加物品
     * @DateTime 2018-08-08T11:49:26+0800
     * @Modify   2018-08-08T11:49:26+0800
     * @Author   Nanuns
     * @param    thingList [description]
     * @return   [description]
     */
    int    add_things(const security_things_t& things);
    /**
     * @Method   query_things
     * @Brief    批量查询物品
     * @DateTime 2018-08-08T11:48:46+0800
     * @Modify   2018-08-08T11:48:46+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    things [description]
     * @return   [description]
     */
    int    query_things(const SecurityParams& params, security_things_t& things);
    /**
     * @Method   update_things
     * @Brief    批量更新物品
     * @DateTime 2018-08-08T11:50:23+0800
     * @Modify   2018-08-08T11:50:23+0800
     * @Author   Nanuns
     * @param    thingList [description]
     * @return   [description]
     */
    int    update_things(const security_things_t& things);
    /**
     * @Method   delete_things
     * @Brief    批量删除物品
     * @DateTime 2018-08-08T11:50:51+0800
     * @Modify   2018-08-08T11:50:51+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_things(const security_idlist_t& ids);
    /**
     * @Method   query_thing
     * @Brief    单个查询物品
     * @DateTime 2018-08-08T11:51:28+0800
     * @Modify   2018-08-08T11:51:28+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    query_thing(const char* id, security_thing_t& thing);
    /**
     * @Method   update_thing
     * @Brief    单个更新物品
     * @DateTime 2018-08-08T11:52:14+0800
     * @Modify   2018-08-08T11:52:14+0800
     * @Author   Nanuns
     * @param    thing [description]
     * @return   [description]
     */
    int    update_thing(const char* id, const security_thing_t& thing);
    /**
     * @Method   delete_thing
     * @Brief    单个删除物品
     * @DateTime 2018-08-08T11:53:32+0800
     * @Modify   2018-08-08T11:53:32+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_thing(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_scenes
     * @Brief    批量添加场景
     * @DateTime 2018-08-08T12:00:09+0800
     * @Modify   2018-08-08T12:00:09+0800
     * @Author   Nanuns
     * @param    sceneList [description]
     * @return   [description]
     */
    int    add_scenes(const security_scenes_t& scenes);
    /**
     * @Method   query_scenes
     * @Brief    批量查询场景
     * @DateTime 2018-08-08T11:59:22+0800
     * @Modify   2018-08-08T11:59:22+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    scenes [description]
     * @return   [description]
     */
    int    query_scenes(const SecurityParams& params, security_scenes_t& scenes);
    /**
     * @Method   update_scene
     * @Brief    批量更新场景
     * @DateTime 2018-08-08T12:01:57+0800
     * @Modify   2018-08-08T12:01:57+0800
     * @Author   Nanuns
     * @param    scenes [description]
     * @return   [description]
     */
    int    update_scenes(const security_scenes_t& scenes);
    /**
     * @Method   delete_scenes
     * @Brief    批量删除场景
     * @DateTime 2018-08-08T12:03:05+0800
     * @Modify   2018-08-08T12:03:05+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_scenes(const security_idlist_t& ids);
    /**
     * @Method   query_scene
     * @Brief    单个查询场景
     * @DateTime 2018-08-08T12:04:03+0800
     * @Modify   2018-08-08T12:04:03+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    query_scene(const char* id, security_scene_t& scene);
    /**
     * @Method   update_scene
     * @Brief    单个更新场景
     * @DateTime 2018-08-08T12:05:08+0800
     * @Modify   2018-08-08T12:05:08+0800
     * @Author   Nanuns
     * @param    scene [description]
     * @return   [description]
     */
    int    update_scene(const char* id, const security_scene_t& scene);
    /**
     * @Method   delete_scene
     * @Brief    单个删除场景
     * @DateTime 2018-08-08T12:05:20+0800
     * @Modify   2018-08-08T12:05:20+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_scene(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_cases
     * @Brief    批量添加视频案事件
     * @DateTime 2018-08-08T12:00:09+0800
     * @Modify   2018-08-08T12:00:09+0800
     * @Author   Nanuns
     * @param    sceneList [description]
     * @return   [description]
     */
    int    add_cases(const security_cases_t& cases);
    /**
     * @Method   query_cases
     * @Brief    批量查询视频案事件
     * @DateTime 2018-08-08T12:10:07+0800
     * @Modify   2018-08-08T12:10:07+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    cases [description]
     * @return   [description]
     */
    int    query_cases(const SecurityParams& params, security_cases_t& cases);
    /**
     * @Method   query_case
     * @Brief    单个查询视频案事件
     * @DateTime 2018-08-08T12:04:03+0800
     * @Modify   2018-08-08T12:04:03+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    caseo [description]
     * @return   [description]
     */
    int    query_case(const char* id, security_case_t& caseo);
    /**
     * @Method   update_case
     * @Brief    批量更新视频案事件
     * @DateTime 2018-08-08T12:05:08+0800
     * @Modify   2018-08-08T12:05:08+0800
     * @Author   Nanuns
     * @param    caseo [description]
     * @return   [description]
     */
    int    update_case(const char* id, const security_case_t& caseo);
    /**
     * @Method   delete_case
     * @Brief    批量删除视频案事件
     * @DateTime 2018-08-08T12:05:20+0800
     * @Modify   2018-08-08T12:05:20+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_case(const char* id);
    /**
     * @Method   query_case_info
     * @Brief    单个查询视频案事件对象信息
     * @DateTime 2018-08-08T13:34:41+0800
     * @Modify   2018-08-08T13:34:41+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    info [description]
     * @return   [description]
     */
    int    query_case_info(const char* id, security_caseinfo_t& info);
    /**
     * @Method   update_case_info
     * @Brief    单个更新视频案事件对象信息
     * @DateTime 2018-08-08T13:34:51+0800
     * @Modify   2018-08-08T13:34:51+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    caseInfo [description]
     * @return   [description]
     */
    int    update_case_info(const char* id, const security_caseinfo_t& info);
    /**
     * @Method   delete_case_info
     * @Brief    单个删除视频案事件对象信息
     * @DateTime 2018-08-08T13:35:02+0800
     * @Modify   2018-08-08T13:35:02+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_case_info(const char* id);
 
    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_dispositions
     * @Brief    批量添加布控对象,实现对视频图像信息对象等的布控
     * @DateTime 2018-08-08T13:40:39+0800
     * @Modify   2018-08-08T13:40:39+0800
     * @Author   Nanuns
     * @param    dispositions [description]
     * @return   [description]
     */
    int    add_dispositions(const security_dispositions_t& dispositions);
    /**
     * @Method   query_dispositions
     * @Brief    批量查询布控任务
     * @DateTime 2018-08-08T13:40:39+0800
     * @Modify   2018-08-08T13:40:39+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    dispositions [description]
     * @return   [description]
     */
    int    query_dispositions(const SecurityParams& params, security_dispositions_t& dispositions);
    /**
     * @Method   update_dispositions
     * @Brief    批量更新布控任务
     * @DateTime 2018-08-08T12:01:57+0800
     * @Modify   2018-08-08T12:01:57+0800
     * @Author   Nanuns
     * @param    dispositions [description]
     * @return   [description]
     */
    int    update_dispositions(const security_dispositions_t& dispositions);
    /**
     * @Method   delete_dispositions
     * @Brief    批量删除布控任务
     * @DateTime 2018-08-08T13:46:52+0800
     * @Modify   2018-08-08T13:46:52+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_dispositions(const security_idlist_t& ids);
    /**
     * @Method   query_disposition
     * @Brief    单个查询布控
     * @DateTime 2018-08-08T13:44:01+0800
     * @Modify   2018-08-08T13:44:01+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    disposition [description]
     * @return   [description]
     */
    int    query_disposition(const char* id, security_disposition_t& disposition);
    /**
     * @Method   update_disposition
     * @Brief    单个更新(撤销)布控
     * @DateTime 2018-08-08T13:49:53+0800
     * @Modify   2018-08-08T13:49:53+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    disposition [description]
     * @return   [description]
     */
    int    update_disposition(const char* id, const security_disposition_t& disposition);
    /**
     * @Method   add_disposition_notifacations
     * @Brief    批量添加告警
     * @DateTime 2018-08-08T13:57:33+0800
     * @Modify   2018-08-08T13:57:33+0800
     * @Author   Nanuns
     * @param    notifications [description]
     * @return   [description]
     */
    int    add_disposition_notifications(const security_disposition_notifications_t& notifications);
    /**
     * @Method   query_disposition_notifications
     * @Brief    批量查询告警
     * @DateTime 2018-08-08T13:57:33+0800
     * @Modify   2018-08-08T13:57:33+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    notifications [description]
     * @return   [description]
     */
    int    query_disposition_notifications(const SecurityParams& params, security_disposition_notifications_t& notifications);
    /**
    * @Method   delete_dispositions
    * @Brief    批量删除告警
    * @DateTime 2018-08-08T13:46:52+0800
    * @Modify   2018-08-08T13:46:52+0800
    * @Author   Nanuns
    * @param    ids [description]
    * @return   [description]
    */
    int    delete_disposition_notifications(const security_idlist_t& ids);
    /**
     * @Method   query_disposition_notifacation
     * @Brief    无效
     * @DateTime 2018-08-08T13:57:28+0800
     * @Modify   2018-08-08T13:57:28+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    notification [description]
     * @return   [description]
     */
    int    query_disposition_notification(const char* id, security_disposition_notification_t& notification);
    /**
     * @Method   delete_disposition_notification
     * @Brief    无效
     * @DateTime 2018-08-08T13:59:46+0800
     * @Modify   2018-08-08T13:59:46+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_disposition_notification(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_subscribes
     * @Brief    批量添加订阅
     * @DateTime 2018-08-08T14:03:22+0800
     * @Modify   2018-08-08T14:03:22+0800
     * @Author   Nanuns
     * @param    subscribes [description]
     * @return   [description]
     */
    int    add_subscribes(const security_subscribes_t& subscribes);
    /**
     * @Method   query_subscribes
     * @Brief    批量添加订阅
     * @DateTime 2018-08-08T14:05:53+0800
     * @Modify   2018-08-08T14:05:53+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    subscribes [description]
     * @return   [description]
     */
    int    query_subscribes(const SecurityParams& params, security_subscribes_t& subscribes);
    /**
     * @Method   update_subscribes
     * @Brief    批量更新订阅
     * @DateTime 2018-08-08T12:01:57+0800
     * @Modify   2018-08-08T12:01:57+0800
     * @Author   Nanuns
     * @param    subscribes [description]
     * @return   [description]
     */
    int    update_subscribes(const security_subscribes_t& subscribes);
    /**
     * @Method   delete_subscribes
     * @Brief    批量删除订阅
     * @DateTime 2018-08-08T14:07:53+0800
     * @Modify   2018-08-08T14:07:53+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_subscribes(const security_idlist_t& ids);
    /**
     * @Method   update_subscribe
     * @Brief    更新(取消)订阅
     * @DateTime 2018-08-08T14:09:53+0800
     * @Modify   2018-08-08T14:09:53+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    subscribe [description]
     * @return   [description]
     */
    int    update_subscribe(const char* id, const security_subscribe_t& subscribe);
    /**
     * @Method   add_subscribe_notifications
     * @Brief    批量添加订阅通知
     * @DateTime 2018-08-08T14:16:02+0800
     * @Modify   2018-08-08T14:16:02+0800
     * @Author   Nanuns
     * @param    notifications [description]
     * @return   [description]
     */
    int    add_subscribe_notifications(const security_subscribe_notifications_t& notifications);
    /**
     * @Method   query_subscribe_notifications
     * @Brief    批量查询订阅通知
     * @DateTime 2018-08-08T14:17:00+0800
     * @Modify   2018-08-08T14:17:00+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    notifications [description]
     * @return   [description]
     */
    int    query_subscribe_notifications(const SecurityParams& params, security_subscribe_notifications_t& notifications);
    /**
     * @Method   delete_subscribe_notifications
     * @Brief    批量删除订阅通知
     * @DateTime 2018-08-08T14:17:35+0800
     * @Modify   2018-08-08T14:17:35+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_subscribe_notifications(const security_idlist_t& ids);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_analysis_rules
     * @Brief    批量添加视频分析规则
     * @DateTime 2018-08-08T14:23:53+0800
     * @Modify   2018-08-08T14:23:53+0800
     * @Author   Nanuns
     * @param    rules [description]
     * @return   [description]
     */
    int    add_analysis_rules(const security_analysis_rules_t& rules);
    /**
     * @Method   query_analysis_rules
     * @Brief    批量查询视频分析规则
     * @DateTime 2018-08-08T14:20:31+0800
     * @Modify   2018-08-08T14:20:31+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    rules [description]
     * @return   [description]
     */
    int    query_analysis_rules(const SecurityParams& params, security_analysis_rules_t& rules);
    /**
     * @Method   update_analysis_rules
     * @Brief    批量更新视频分析规则
     * @DateTime 2018-08-08T14:26:06+0800
     * @Modify   2018-08-08T14:26:06+0800
     * @Author   Nanuns
     * @param    analysisRuleList [description]
     * @return   [description]
     */
    int    update_analysis_rules(const security_analysis_rules_t& rules);
    /**
     * @Method   delete_analysis_rules
     * @Brief    批量删除视频分析规则
     * @DateTime 2018-08-08T14:27:02+0800
     * @Modify   2018-08-08T14:27:02+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_analysis_rules(const security_idlist_t& ids);
    /**
     * @Method   add_analysis_rule
     * @Brief    单个添加视频分析规则
     * @DateTime 2018-08-08T14:34:04+0800
     * @Modify   2018-08-08T14:34:04+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    rule [description]
     * @return   [description]
     */
    int    add_analysis_rule(const char* id, const security_analysis_rule_t& rule);
    /**
     * @Method   query_analysis_rule
     * @Brief    单个查询视频分析规则
     * @DateTime 2018-08-08T14:32:23+0800
     * @Modify   2018-08-08T14:32:23+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    rule [description]
     * @return   [description]
     */
    int    query_analysis_rule(const char* id, security_analysis_rule_t& rule);
    /**
     * @Method   update_analysis_rule
     * @Brief    单个更新视频分析规则
     * @DateTime 2018-08-08T14:35:01+0800
     * @Modify   2018-08-08T14:35:01+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    rule [description]
     * @return   [description]
     */
    int    update_analysis_rule(const char* id, const security_analysis_rule_t& rule);
    /**
     * @Method   delete_analysis_rule
     * @Brief    单个删除视频分析规则
     * @DateTime 2018-08-08T14:35:56+0800
     * @Modify   2018-08-08T14:35:56+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_analysis_rule(const char* id);

    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @Method   add_video_labels
     * @Brief    批量添加视频图像标签
     * @DateTime 2018-08-08T14:45:53+0800
     * @Modify   2018-08-08T14:45:53+0800
     * @Author   Nanuns
     * @param    labels [description]
     * @return   [description]
     */
    int    add_video_labels(const security_videolabels_t& labels);
    /**
     * @Method   query_video_labels
     * @Brief    批量查询视频图像标签
     * @DateTime 2018-08-08T14:45:43+0800
     * @Modify   2018-08-08T14:45:43+0800
     * @Author   Nanuns
     * @param    params [description]
     * @param    labels [description]
     * @return   [description]
     */
    int    query_video_labels(const SecurityParams& params, security_videolabels_t& labels);
    /**
     * @Method   update_video_labels
     * @Brief    批量更新视频图像标签
     * @DateTime 2018-08-08T14:46:25+0800
     * @Modify   2018-08-08T14:46:25+0800
     * @Author   Nanuns
     * @param    labels [description]
     * @return   [description]
     */
    int    update_video_labels(const security_videolabels_t& labels);
    /**
     * @Method   delete_video_labels
     * @Brief    批量删除视频图像标签
     * @DateTime 2018-08-08T14:46:32+0800
     * @Modify   2018-08-08T14:46:32+0800
     * @Author   Nanuns
     * @param    ids [description]
     * @return   [description]
     */
    int    delete_video_labels(const security_idlist_t& ids);
    /**
     * @Method   add_video_label
     * @Brief    单个添加视频图像标签
     * @DateTime 2018-08-08T14:53:16+0800
     * @Modify   2018-08-08T14:53:16+0800
     * @Author   Nanuns
     * @param    videoLabel [description]
     * @return   [description]
     */
    int    add_video_label(const char* id, const security_videolabel_t& label);
    /**
     * @Method   query_video_label
     * @Brief    单个查询视频图像标签
     * @DateTime 2018-08-08T14:53:04+0800
     * @Modify   2018-08-08T14:53:04+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    label [description]
     * @return   [description]
     */
    int    query_video_label(const char* id, security_videolabel_t& label);
    /**
     * @Method   update_video_label
     * @Brief    单个更新视频图像标签
     * @DateTime 2018-08-08T14:53:28+0800
     * @Modify   2018-08-08T14:53:28+0800
     * @Author   Nanuns
     * @param    id [description]
     * @param    label [description]
     * @return   [description]
     */
    int    update_video_label(const char* id, const security_videolabel_t& label);
    /**
     * @Method   delete_video_label
     * @Brief    单个删除视频图像标签
     * @DateTime 2018-08-08T14:53:44+0800
     * @Modify   2018-08-08T14:53:44+0800
     * @Author   Nanuns
     * @param    id [description]
     * @return   [description]
     */
    int    delete_video_label(const char* id);
    ///////////////////////////////////////////////////////////////////////////////////////////

private:
    /**
     * @Method   add_list
     * @Brief
     * @DateTime 2018-08-06T12:27:44+0800
     * @Modify   2018-08-06T12:27:44+0800
     * @Author   Nanuns
     * @param    msg     待添加的内容
     * @param    viidUri 请求viid uri
     * @return   0成功, 其他失败
     */
    int    add_list(const string& msg, const char* viidUri);
    /**
     * @Method   add_object
     * @Brief
     * @DateTime 2018-08-06T12:27:44+0800
     * @Modify   2018-08-06T12:27:44+0800
     * @Author   Nanuns
     * @param    id       待添加的id
     * @param    msg      待添加的内容
     * @param    viidUri  请求viid uri
     * @param    otherUri 请求详细的viid uri
     * @return   0成功, 其他失败
     */
    int    add_object(const char* id, const string& msg, const char* viidUri, const char* otherUri = NULL);

    /**
     * @Method   query_list
     * @Brief
     * @DateTime 2018-08-06T12:06:58+0800
     * @Modify   2018-08-06T12:06:58+0800
     * @Author   Nanuns
     * @param    params  查询条件组合,如果为空时表示不限制条件
     * @param    body    查询响应的内容
     * @param    viidUri 请求viid uri
     * @return   0成功, 其他失败
     */
    int    query_list(const SecurityParams& params, string& body, const char* viidUri);
    /**
     * @Method   query_object
     * @Brief
     * @DateTime 2018-08-06T14:29:40+0800
     * @Modify   2018-08-06T14:29:40+0800
     * @Author   Nanuns
     * @param    id       待查询的id
     * @param    body     查询响应的内容
     * @param    viidUri  请求viid uri
     * @param    otherUri 请求详细的viid uri
     * @return   0成功, 其他失败
     */
    int    query_object(const char* id, string& body, const char* viidUri, const char* otherUri = NULL);

    /**
     * @Method   update_list
     * @Brief
     * @DateTime 2018-08-08T10:47:39+0800
     * @Modify   2018-08-08T10:47:39+0800
     * @Author   Nanuns
     * @param    msg 待更新的内容
     * @param    viidUri 请求viid uri
     * @return   0成功, 其他失败
     */
    int    update_list(const string& msg, const char* viidUri);
    /**
     * @Method   update_object
     * @Brief
     * @DateTime 2018-08-08T10:57:35+0800
     * @Modify   2018-08-08T10:57:35+0800
     * @Author   Nanuns
     * @param    id       待更新的id
     * @param    msg      待更新的内容
     * @param    viidUri  请求viid uri
     * @param    otherUri 请求详细的viid uri
     * @return   0成功, 其他失败
     */
    int    update_object(const char* id, const string& msg, const char* viidUri, const char* otherUri = NULL);

    /**
     * @Method   delete_list
     * @Brief
     * @DateTime 2018-08-08T10:47:39+0800
     * @Modify   2018-08-08T10:47:39+0800
     * @Author   Nanuns
     * @param    ids     待更新所有id
     * @param    viidUri 请求viid uri
     * @return   0成功, 其他失败
    */
    int    delete_list(const security_idlist_t& ids, const char* viidUri);
    /**
     * @Method   delete_object
     * @Brief
     * @DateTime 2018-01-08T11:10:10+0800
     * @Modify   2018-01-08T11:10:10+0800
     * @Author   Nanuns
     * @param    id       待删除的id
     * @param    viidUri  请求viid uri
     * @param    otherUri 请求详细的viid uri
     * @return   0成功, 其他失败
     */
    int    delete_object(const char* id, const char* viidUri, const char* otherUri = NULL);

private:
    volatile bool registered = false;
    string ip;
    int port;
    string deviceId;
    string username;
    string password;

    security_message_factory msgFactory;

    int64_t lastTime = 0;
};


#endif
