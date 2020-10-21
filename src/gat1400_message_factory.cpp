/**
 * @File     gat1400_message_factory.cpp
 * @brief    
 * @DateTime 2018/2/4 10:21:23
 * @Author   Nanuns
 */
#include "gat1400_message_factory.h"
#include "gat1400_rest.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;


SecurityString security_message_factory::makeRegisterMessage(const char* deviceId) {
    json jRegister, jDeviceID;
    jDeviceID["DeviceID"] = deviceId;
    jRegister["RegisterObject"] = jDeviceID;
    SecurityString str = jRegister.dump();
    printf("%s\n", str.c_str());
    return str;
}


SecurityString security_message_factory::makeUnregisterMessage(const char* deviceId) {
    json jUnRegister, jDeviceID;
    jDeviceID["DeviceID"] = deviceId;
    jUnRegister["UnRegisterObject"] = jDeviceID;
    SecurityString str = jUnRegister.dump();
    printf("%s\n", str.c_str());
    return str;
}

SecurityString security_message_factory::makeKeepaliveMessage(const char* deviceId) {
    json jKeepalive, jDeviceID;
    jDeviceID["DeviceID"] = deviceId;
    jKeepalive["KeepaliveObject"] = jDeviceID;
    SecurityString str = jKeepalive.dump();
    printf("%s\n", str.c_str());
    return str;
}

SecurityString security_message_factory::makeTimeMessage(const security_system_time_t& time) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeAPEListMessage(const security_apes_t& apes) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoSliceListMessage(const security_videoslices_t& slice) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoSliceMessage(const security_videoslice_t& slice) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoSliceInfoListMessage(const security_videoslice_infos_t& infos) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoSliceInfoMessage(const security_videoslice_info_t& info) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeImageListMessage(const security_images_t& images) {
    if (images.empty()) {
        return SECURITY_STRING_EMPTY;
    }

    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeImageMessage(const security_image_t& info) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeImageInfoMessage(const security_image_info_t& info) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFileListMessage(const security_files_t& files) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFileMessage(const security_file_t& file) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFileInfoMessage(const security_file_info_t& file) {
    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makePersonListMessage(const security_persons_t& persons) {
    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makePersonMessage(const security_person_t& person) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFaceListMessage(const security_faces_t& faces) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeFaceMessage(const security_face_t& face) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeMotorVehicleListMessage(const security_motorvehicles_t& motorVehicles) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeMotorVehicleMessage(const security_motorvehicle_t& motorVehicle) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeNonMotorVehicleListMessage(const security_nonmotorvehicles_t& nonMotorVehicles) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeNonMotorVehicleMessage(const security_nonmotorvehicle_t& nonmotorVehicle) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeThingListMessage(const security_things_t& things) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeThingMessage(const security_thing_t& thing) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeSceneListMessage(const security_scenes_t& scenes) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeSceneMessage(const security_scene_t& scene) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeCaseListMessage(const security_cases_t& cases) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeCaseMessage(const security_case_t& caseo) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeCaseInfoMessage(const security_caseinfo_t& info) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeDispositionMessage(const security_disposition_t& disp) {
    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeDispositionListMessage(const security_dispositions_t& disps) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeDispositionNotificationListMessage(const security_disposition_notifications_t& notifications) {
    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeDispositionNotificationMessage(const security_disposition_notification_t& notification) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeSubscribeListMessage(const security_subscribes_t& subscribes) {
    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeSubscribeMessage(const security_subscribe_t& subscribe) {
    // TODO
    return SECURITY_STRING_EMPTY;
}
SecurityString security_message_factory::makeSubscribeNotificationListMessage(const security_subscribe_notifications_t& notifications) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeAnalysisRuleListMessage(const security_analysis_rules_t& rules) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeAnalysisRuleMessage(const security_analysis_rule_t& rule) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoLabelListMessage(const security_videolabels_t& labels) {
    // TODO
    return SECURITY_STRING_EMPTY;
}

SecurityString security_message_factory::makeVideoLabelMessage(const security_videolabel_t& label) {
    // TODO
    return SECURITY_STRING_EMPTY;
}


NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_response_status_t, RequestURL, StatusCode, StatusString, Id, LocalTime)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_system_time_t, VIIDServerID, TimeMode, LocalTime, TimeZone)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_videoslice_info_t, VideoID, InfoKind, VideoSource, IsAbstractVideo, OriginVideoID,
    OriginVideoURL, EventSort, DeviceID, StoragePath, ThumbnailStoragePath, FileHash, FileFormat, CodedFormat, AudioFlag,
    AudioCodedFormat, Title, TitleNote, SpecialName, Keyword, ContentDescription, MainCharacter, ShotPlaceCode, ShotPlaceFullAdress,
    ShotPlaceLongitude, ShoPlacetLatitude, ShotPlaceLatitude, HorizontalShotDirection, VerticalShotDirection, SecurityLevel, VideoLen,
    BeginTime, EndTime, TimeErr, Width, Height, QualityGrade, CollectorName, CollectorOrg, CollectorIDType, CollectorID,
    EntryClrk, EntryClrkOrg, EntryClrkIDType, EntryClrkID, EntryTime, VideoProcFlag, FileSize)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_image_info_t, ImageID, InfoKind, ImageSource, SourceVideoID, OriginImageID, EventSort,
    DeviceID, StoragePath, FileHash, FileFormat, ShotTime, Title, TitleNote, SpecialIName, KeyWord, ContentDescription, SubjectCharacter,
    ShotPlaceCode, shotPlaceFullAddress, ShotPlaceLongitude, ShotPlaceLatitude, HorizontalShotDirection, VerticalShotDirection,
    SecurityLevel, Width, Height, CameraManufacturer, CameraVersion, ApertureValue, ISOSensitivity, FocalLength, QualityGrade,
    CollectorName, CollectorOrg, CollectorIDType, CollectorID, EntryClrk, EntryClrkOrg, EntryClrkIDType, EntryTime, ImageProcFlag, FileSize)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_subimage_info_t, ImageID, EventSort, DeviceID, StoragePath, Type, FileFormat, ShotTime, Width, Height, Data)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_file_info_t, FileID, InfoKind, Source, FileName, StoragePath, FileHash, FileFormat,
    Title, SecurityLevel, SubmiterName, SubmiterOrg, EntryTime, FileSize)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_person_t, PersionID, InfoKind, SourceID, DeviceID, LeftTopX, LeftTopY, RightBtmX, RightBtmY,
    LocationMarkTime, PersonAppearTime, PersonDisAppearTime, IDType, IDNumber, Name, UsedName, Alias, GenderCode, AgeUpLimit, AgeLowerLimit,
    EthicCode, NationalityCode, NativeCityCode, ResidenceAdminDivision, ChineseAccentCode, PersonOrg, JobCategory, AccompanyNumber,
    HeightUpLimit, HeightLowerLimit, BodyType, SkinColor, HairStyle, HairColor, Gesture, Status, FaceStyle, FacialFeature, PhysicalFeature,
    BodyFeature, HabitualMovement, Behavior, BehaviorDescription, Appendant, AppendantDescription, UmbrellaColor, RespiratorColor,
    CapStyle, CapColor, GlassStyle, GlassColor, ScarfColor, BagStyle, BagColor, CoatStyle, CoatLength, CoatColor,
    TrousersStyle, TrousersColor, TrousersLen, ShoesStyle, ShoesColor, IsDriver, IsForeigner, PassportType, ImmigrantTypeCode,
    IsSuspectedTerrorist, SuspectedTerroristNumber, IsCriminalInvolved, CriminalInvolvedSpecilisationCode, BodySpeciallMark,
    CrimeMethod, CrimeCharacterCode, EscapedCriminalNumber, IsDetainees, DetentionHouseCode, DetaineesIdentity, DetaineesSpecialIdentity,
    MemberTypeCode, IsVictim, VictimType, InjuredDegree, CorpseConditionCode, IsSuspiciousPerson, SubImageList)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_face_t, FaceID, InfoKind, SourceID, DeviceID, LeftTopX, LeftTopY, RightBtmX, RightBtmY,
    LocationMarkTime, FaceAppearTime, FaceDisAppearTime, IDType, IDNumber, Name, UsedName, Alias, GenderCode, AgeUpLimit,
    AgeLowerLimit, EthicCode, NationalityCode, NativeCityCode, ResidenceAdminDivision, ChineseAccentCode, JobCategory,
    AccompanyNumber, SkinColor, HairStyle, HairColor, FaceStyle, FacialFeature, PhysicalFeature, RespiratorColor, CapStyle, CapColor,
    GlassStyle, GlassColor, IsDriver, IsForeigner, PassportType, ImmigrantTypeCode, IsSuspectedTerrorist, SuspectedTerroristNumber,
    IsCriminalInvolved, CriminalInvolvedSpecilisationCode, BodySpeciallMark, CrimeMethod, CrimeCharacterCode, EscapedCriminalNumber,
    IsDetainees, DetentionHouseCode, DetaineesIdentity, DetaineesSpecialIdentity, MemberTypeCode, IsVictim, VictimType,
    InjuredDegree, CorpseConditionCode, IsSuspiciousPerson, Attitude, Similaritydegree, EyebrowStyle, NoseStyle, MustacheStyle,
    LipStyle, WrinklePouch, AcneStain, FreckleBirthmark, ScarDimple, OtherFeature, SubImageList)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_motorvehicle_t, MotorVehicleID, InfoKind, SourceID, TollgateID, DeviceID,
    StorageUrl1, StorageUrl2, StorageUrl3, StorageUrl4, StorageUrl5, LeftTopX, LeftTopY, RightBtmX, RightBtmY, MarkTime,
    AppearTime, DisappearTime, LaneNo, HasPlate, PlateClass, PlateColor, PlateNo, PlateNoAttach, PlateDescribe, IsDecked, IsAltered,
    IsCovered, Speed, Direction, DrivingStatusCode, UsingPropertiesCode, VehicleClass, VehicleBrand, VehicleModel, VehicleStyles,
    VehicleLength, VehicleWidth, VehicleHeight, VehicleColor, VehicleColorDepth, VehicleHood, VehicleTrunk, VehicleWheel,
    WheelPrintedPattern, VehicleWindow, VehicleRoof, VehicleDoor, SideOfVehicle, CarOfVehicle, RearviewMirror, VehicleChassis,
    VehicleShielding, FilmColor, IsModified, HitMarkInfo, VehicleBodyDesc, VehicleFrontItem, DescOfFrontItem, VehicleRearItem,
    DescOfRearItem, NumOfPassenger, PassTime, NameOfPassedRoad, IsSuspicious, Sunvisor, SafetyBelt, Calling,
    PlateReliability, PlateCharReliability, BrandReliability, SubImageList)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_nonmotorvehicle_t, NonMotorVehicleID, InfoKind, SourceID, DeviceID, LeftTopX, LeftTopY,
    RightBtmX, RightBtmY, MarkTime, AppearTime, DisappearTime, HasPlate, PlateClass, PlateColor, PlateNo, PlateNoAttach, PlateDescribe,
    IsDecked, IsAltered, IsCovered, Speed, DrivingStatusCode, UsingPropertiesCode, VehicleBrand, VehicleType, VehicleLength,
    VehicleWidth, VehicleHeight, VehicleColor, VehicleHood, VehicleTrunk, VehicleWheel, WheelPrintedPattern, VehicleWindow, VehicleRoof,
    VehicleDoor, SideOfVehicle, CarOfVehicle, RearviewMirror, VehicleChassis, VehicleShielding, FilmColor, IsModified, SubImageList)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_thing_t, ThingID, InfoKind, SourceID, DeviceID, LeftTopX, LeftTopY, RightBtmX,
    RightBtmY, LocationMarkTime, AppearTime, DisappearTime, Name, Shape, Color, Size, Material, Characteristic,
    Propertiy, InvolvedObjectType, FirearmsAmmunitionType, ToolTraceType, EvidenceType, CaseEvidenceType, SubImageList)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_scene_t, SceneID, InfoKind, SourceID, DeviceID, BeginTime, PlaceType, WeatherType,
    SceneDescribe, SceneType, RoadAlignmentType, RoadTerraintype, RoadSurfaceType, RoadCoditionType, RoadJunctionSectionType,
    RoadLightingType, Illustration, WindDirection, Illumination, FieldCondition, Temperature, Humidity, PopulationDensity,
    DenseDegree, Importance, SubImageList)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_caseinfo_t, CaseID, CaseLinkMark, CaseName, CaseAbstract, ClueID, TimeUpLimit, TimeLowerLimit,
    CreateTime, PlaceCode, PlaceFullAddress, SuspectNumber, WitnessIDs, CreatorName, CreatorIDType, CreatorID, CreatorOrg,
    Longitude, Latitude, MotorVehicleIDs, NonMotorVehicleIDs, PersonIDs, FaceIDs, ThingIDs, FileIDs, SceneIDs, RelateCaseIdList, ParentCaseId, State)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_videolabel_t::color_area_t, AreaPosX, AreaPosY, AreaWidth, AreaHeight)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_videolabel_t::target_t, PosX, PosY, Width, Height, Status, SpeedVal, SpeedRad)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_videolabel_t::behavior_analysis_t, EventLevel, BehaviorBeginTime, BehaviorBeginTimeRlt,
    BehaviorBeginFrameNoRlt, BehaviorEndTime, BehaviorEndTimeRlt, BehaviorEndFrameNoRlt)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_videolabel_t, VideoLabelID, EventSort, EventRuleID, VideoImageID, VideoImageUrl, CameraID,
    IVADeviceID, CreateTimeAbs, CreateTimeRlt, CreateFrameNoRlt, PersonID, FaceID, MotorVehicleID, NonMotorVehicleID, ThingID, SceneID,
    TargetColor, ColorCount, ColorAreaSet, MoveObjectNum, MoveObjectSet, BehaviorAnalysisObject, ImagePath, Desc, TargetNum, PersonNum,
    FaceNum, VehicleNum, ThingNum, TargetDensityAbs, PersonDensityAbs, FacenDensityAbs, VehicleDensityAbs, ThingDensityAbs,
    TargetDensityRlt, PersonDensityRlt, FacenDensityRlt, VehicleDensityRlt, ThingDensityRlt, TotalTargetFlowRate, PersonFlowRate, VehicleFlowRate, FlowDirection)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_analysis_rule_t::point_t, PointX, PointY)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_analysis_rule_t::line_t, Direction, PointObjectList)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_analysis_rule_t::direction_type_t, Direction, TargetType)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_analysis_rule_t, AnalysisRuleID, VideoImageID, VideoImageUrl, CameraID, Width, Height,
    MinDuration, LineMinDuration, LineMaxDuration, MaxDuration, LineNum, LineSet, PointNum, PointID, PointSet, Direction, ActionType,
    BeginPointX, BeginPointY, EndPointX, EndPointY, DirectionNum, DirectionSet, DensityUnit)

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_image_t, ImageInfo, PersonList, FaceList, MotorVehicleList, NonMotorVehicleList, ThingList, SceneList, Data)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_videoslice_t, VideoSliceInfo, PersonList, FaceList, MotorVehicleList, NonmotorVehicleList, ThingList, SceneList, Data)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_file_t, FileInfo, PersonList, FaceList, MotorVehicleList, NonMotorVehicleList, ThingList, SceneList, Data)
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(security_case_t, CaseInfo, VideoSliceList, ImageList, FileList, PersonList, FaceList, MotorVehicleList, NonMotorVehicleList, ThingList, SceneList)

/**
    {
        "ResponseStatusListObject": {
            "ResponseStatusObject": [
            {
                "RequestURL": "http://localhost:8080/VIID/Images",
                "StatusCode": 0,
                "StatusString": "正常",
                "Id": "33010101001210000001022017093009520000031",
                "LocalTime": "20171220204451"
            }
            ]
        }
    }
 */
int security_message_factory::parseResponseStatusList(const char* body, security_response_statuss_t& statuss) {
    try {
        json j = json::parse(body);
        statuss = j["ResponseStatusListObject"]["ResponseStatusObject"].get<security_response_statuss_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseResponseStatusList error %s\n", e.what());
    }
    return -1;
}

/**
   {
     "ResponseStatusObject": {
        "RequestURL": "http://localhost:8080/VIID/Register",
        "StatusCode": 0,
        "StatusString": "正常",
        "Id": "33010299011190000253",
        "LocalTime": "20171220204451"
      }
   }
 */
int security_message_factory::parseResponseStatus(const char* body, security_response_status_t& status) {
    try {
        json j = json::parse(body);
        status = j["ResponseStatusObject"].get<security_response_status_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseResponseStatus error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseSystemTime(const char* body, security_system_time_t& time) {
    try {
        json j = json::parse(body);
        time = j["SystemTimeObject"].get<security_system_time_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseSystemTime error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseApeList(const char* body, security_apes_t& apes) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseApeList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseApsList(const char* body, security_apss_t& apss) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseApsList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseTollgateList(const char* body, security_tollgates_t& tatollgates) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseTollgateList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseLaneList(const char* body, security_lanes_t& lanes) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseLaneList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseVideoSliceList(const char* body, security_videoslices_t& slices) {
    try {
        json j = json::parse(body);
        slices = j["VideoSliceListObject"]["VideoSlice"].get<security_videoslices_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseVideoSliceList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseVideoSlice(const char* body, security_videoslice_t& slice) {
    try {
        json j = json::parse(body);
        slice = j["VideoSliceObject"].get<security_videoslice_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseVideoSlice error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseVideoSliceInfo(const char* body, security_videoslice_info_t& info) {
    try {
        json j = json::parse(body);
        info = j["VideoSliceInfoObject"].get<security_videoslice_info_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseVideoSliceInfo error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseFileList(const char* body, security_files_t& files) {
    try {
        json j = json::parse(body);
        files = j["FileListObject"]["File"].get<security_files_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseFileList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseFile(const char* body, security_file_t& file) {
    try {
        json j = json::parse(body);
        file = j["FileObject"].get<security_file_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseFile error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseFileInfo(const char* body, security_file_info_t& info) {
    try {
        json j = json::parse(body);
        info = j["FileInfoObject"].get<security_file_info_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseFileInfo error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parsePersonList(const char* body, security_persons_t& persons) {
    try {
        json j = json::parse(body);
        persons = j["PersonListObject"]["PersonObject"].get<security_persons_t>();
        return 0;
    }
    catch (exception e) {
        printf("parsePersonList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parsePerson(const char* body, security_person_t& person) {
    try {
        json j = json::parse(body);
        person = j["PersonObject"].get<security_person_t>();
        return 0;
    }
    catch (exception e) {
        printf("parsePerson error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseThingList(const char* body, security_things_t& things) {
    try {
        json j = json::parse(body);
        things = j["ThingListObject"]["ThingObject"].get<security_things_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseThingList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseThing(const char* body, security_thing_t& thing) {
    try {
        json j = json::parse(body);
        thing = j["ThingObject"].get<security_thing_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseThing error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseSceneList(const char* body, security_scenes_t& scenes) {
    try {
        json j = json::parse(body);
        scenes = j["SceneListObject"]["SceneObject"].get<security_scenes_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseSceneList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseScene(const char* body, security_scene_t& scene) {
    try {
        json j = json::parse(body);
        scene = j["SceneObject"].get<security_scene_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseScene error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseImageList(const char* body, security_images_t& images) {
    try {
        json j = json::parse(body);
        images = j["ImageListObject"]["Image"].get<security_images_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseImageList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseImage(const char* body, security_image_t& image) {
    try {
        json j = json::parse(body);
        image = j["ImageObject"].get<security_image_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseImage error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseImageInfo(const char* body, security_image_info_t& info) {
    try {
        json j = json::parse(body);
        info = j["ImageInfoObject"].get<security_image_info_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseImageInfo error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseCaseList(const char* body, security_cases_t& cases) {
    try {
        json j = json::parse(body);
        cases = j["CaseListObject"]["Case"].get<security_cases_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseCaseList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseCase(const char* body, security_case_t& caseo) {
    try {
        json j = json::parse(body);
        caseo = j["CaseObject"].get<security_case_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseCase error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseCaseInfo(const char* body, security_caseinfo_t& info) {
    try {
        json j = json::parse(body);
        info = j["CaseInfoObject"].get<security_caseinfo_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseCaseInfo error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseDispositionList(const char* body, security_dispositions_t& dispositions) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseDispositionsList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseDisposition(const char* body, security_disposition_t& disposition) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseDisposition error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseDispositionNotificationList(const char* body, security_disposition_notifications_t& notifications) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseDispositionNotificationList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseDispositionNotification(const char* body, security_disposition_notification_t& notification) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseDispositionNotification error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseSubscribeList(const char* body, security_subscribes_t& subscribes) {
    try {
        json j = json::parse(body);
        //subscribes = j["SubscribeListObject"]["SubscribeObject"].get<security_subscribes_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseSubscribeList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseSubscribe(const char* body, security_subscribe_t& subscribe) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseSubscribe error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseSubscribeNotificationList(const char* body, security_subscribe_notifications_t& notifications) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseSubscribeNotificationList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseSubscribeNotification(const char* body, security_subscribe_notification_t& notification) {
    try {
        json j = json::parse(body);
        // TODO
        return 0;
    }
    catch (exception e) {
        printf("parseSubscribeNotification error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseAanalysisRuleList(const char* body, security_analysis_rules_t& rules) {
    try {
        json j = json::parse(body);
        rules = j["AnalysisRuleListObject"]["AnalysisRuleObject"].get<security_analysis_rules_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseAanalysisRuleList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseAanalysisRule(const char* body, security_analysis_rule_t& rule) {
    try {
        json j = json::parse(body);
        rule = j["AnalysisRuleObject"].get<security_analysis_rule_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseAanalysisRule error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseVideoLabelList(const char* body, security_videolabels_t& labels) {
    try {
        json j = json::parse(body);
        labels = j["VideoLabelListObject"]["VideoLabelObject"].get<security_videolabels_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseVideoLabelList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseVideoLabel(const char* body, security_videolabel_t& label) {
    try {
        json j = json::parse(body);
        label = j["VideoLabelObject"].get<security_videolabel_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseVideoLabel error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseFaceList(const char* body, security_faces_t& faces) {
    try {
        json j = json::parse(body);
        faces = j["FaceListObject"]["FaceObject"].get<security_faces_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseImageList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseFace(const char* body, security_face_t& face) {
    try {
        json j = json::parse(body);
        face = j["FaceObject"].get<security_face_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseImage error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseMotorVehicleList(const char* body, security_motorvehicles_t& motorvehicles) {
    try {
        json j = json::parse(body);
        motorvehicles = j["MotorVehicleListObject"]["MotorVehicleObject"].get<security_motorvehicles_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseMotorVehicleList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseMotorVehicle(const char* body, security_motorvehicle_t& motorvehicle) {
    try {
        json j = json::parse(body);
        motorvehicle = j["MotorVehicleObject"].get<security_motorvehicle_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseMotorVehicle error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseNonMotorVehicleList(const char* body, security_nonmotorvehicles_t& nonmotorvehicles) {
    try {
        json j = json::parse(body);
        nonmotorvehicles = j["NonMotorVehicleListObject"]["NonMotorVehicleObject"].get<security_nonmotorvehicles_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseNonMotorVehicleList error %s\n", e.what());
    }
    return -1;
}

int security_message_factory::parseNonMotorVehicle(const char* body, security_nonmotorvehicle_t& nonmotorvehicle) {
    try {
        json j = json::parse(body);
        nonmotorvehicle = j["NonMotorVehicleObject"].get<security_nonmotorvehicle_t>();
        return 0;
    }
    catch (exception e) {
        printf("parseNonMotorVehicle error %s\n", e.what());
    }
    return -1;
}
