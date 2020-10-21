/**
 * @File     gat1400_types.h
 * @brief
 * @DateTime 2018/2/4 10:21:23
 * @Author   Nanuns
 */
#ifndef __GAT1400_TYPES_H_
#define __GAT1400_TYPES_H_

#include <string>
#include <vector>
#include <map>
#include "gat1400_category.h"

#define SecurityArray  std::vector
#define SecurityString std::string
#define SpeedType      double
#define LongitudeType  double
#define LatitudeType   double

using SecurityParams = std::multimap<std::string, std::string>;

typedef SecurityArray<SecurityString>  security_idlist_t;

/**
 * @Struct   security_videoslice_info_t
 * @Brief    VideoSliceInfo
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Nanuns
 */
typedef struct _security_videoslice_info_t {
    SecurityString VideoID;
    SecurityInfoType InfoKind;
    SecurityString VideoSource;
    SecurityString IsAbstractVideo;
    SecurityString OriginVideoID;
    SecurityString OriginVideoURL;
    SecurityString EventSort;
    SecurityString DeviceID;
    SecurityString StoragePath;
    SecurityString ThumbnailStoragePath;
    SecurityString FileHash;
    SecurityString FileFormat;
    SecurityString CodedFormat;
    int            AudioFlag;
    SecurityString AudioCodedFormat;
    SecurityString Title;
    SecurityString TitleNote;
    SecurityString SpecialName;
    SecurityString Keyword;
    SecurityString ContentDescription;
    SecurityString MainCharacter;
    SecurityString ShotPlaceCode;
    SecurityString ShotPlaceFullAdress;
    LongitudeType  ShotPlaceLongitude;
    LatitudeType   ShoPlacetLatitude;
    LatitudeType   ShotPlaceLatitude; // TODO
    SecurityString HorizontalShotDirection;
    SecurityString VerticalShotDirection;
    SecurityString SecurityLevel;
    double         VideoLen;
    SecurityString BeginTime;
    SecurityString EndTime;
    int            TimeErr;
    int            Width;
    int            Height;
    SecurityString QualityGrade;
    SecurityString CollectorName;
    SecurityString CollectorOrg;
    SecurityString CollectorIDType;
    SecurityString CollectorID;
    SecurityString EntryClrk;
    SecurityString EntryClrkOrg;
    SecurityString EntryClrkIDType;
    SecurityString EntryClrkID;
    SecurityString EntryTime;
    int            VideoProcFlag;
    int64_t        FileSize;
} security_videoslice_info_t;
typedef SecurityArray<security_videoslice_info_t> security_videoslice_infos_t;

/**
 * @Struct   security_image_info_t
 * @Brief    ImageInfo 图像对象
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
typedef struct _security_image_info {
    SecurityString ImageID;             // R/O
    SecurityInfoType InfoKind;          // R 信息分类，人工采集还是自动采集
    SecurityString ImageSource;         // R 图像来源
    SecurityString SourceVideoID;       // O 来源视频标识，如果此图像是视频截图，此字段是来源视频的视频ID
    SecurityString OriginImageID;       // R/O 原始图像标识
    SecurityString EventSort;
    SecurityString DeviceID;
    SecurityString StoragePath;
    SecurityString FileHash;
    SecurityString FileFormat;
    SecurityString ShotTime;
    SecurityString Title;
    SecurityString TitleNote;
    SecurityString SpecialIName;
    SecurityString KeyWord;
    SecurityString ContentDescription;
    SecurityString SubjectCharacter;
    SecurityString ShotPlaceCode;
    SecurityString shotPlaceFullAddress;
    LongitudeType  ShotPlaceLongitude;
    LatitudeType   ShotPlaceLatitude;
    SecurityString HorizontalShotDirection;
    SecurityString VerticalShotDirection;
    SecurityString SecurityLevel;
    int            Width;
    int            Height;
    SecurityString CameraManufacturer;
    SecurityString CameraVersion;
    int            ApertureValue;
    int            ISOSensitivity;              // ISO感光值
    int            FocalLength;
    SecurityString QualityGrade;
    SecurityString CollectorName;
    SecurityString CollectorOrg;
    SecurityString CollectorIDType;
    SecurityString CollectorID;
    SecurityString EntryClrk;
    SecurityString EntryClrkOrg;
    SecurityString EntryClrkIDType;
    SecurityString EntryTime;
    SecurityString ImageProcFlag;
    int            FileSize;
} security_image_info_t;
typedef SecurityArray<security_image_info_t>                security_image_infos_t;

/**
 * @Struct   security_subimage_info_t
 * @Brief    SubImageInfo 图像子对象，人、车、物等对象可以包含一个或者多个图像子对象。
 * @DateTime 2018-08-10T11:18:46+0800
 * @Modify   2018-08-10T11:18:46+0800
 * @Author   Nanuns
 */
typedef struct _security_subimage_info_t {
    SecurityString  ImageID;
    int             EventSort;
    SecurityString  DeviceID;
    SecurityString  StoragePath;
    SecurityString  Type;
    SecurityString  FileFormat;
    SecurityString  ShotTime;
    int             Width;
    int             Height;
    SecurityString  Data; // base64Binary
} security_subimage_info_t;
typedef SecurityArray<security_subimage_info_t> security_subimage_infos_t;


/**
 * @Struct   security_face_t
 * @Brief    人脸对象
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
typedef struct _security_face_t {
    SecurityString FaceID;
    SecurityInfoType InfoKind;
    SecurityString SourceID;
    SecurityString DeviceID;
    int            LeftTopX;
    int            LeftTopY;
    int            RightBtmX;
    int            RightBtmY;
    SecurityString LocationMarkTime;
    SecurityString FaceAppearTime;
    SecurityString FaceDisAppearTime;
    SecurityString IDType;
    SecurityString IDNumber;
    SecurityString Name;
    SecurityString UsedName;
    SecurityString Alias;
    SecurityString GenderCode;
    int            AgeUpLimit;
    int            AgeLowerLimit;
    SecurityString EthicCode;
    SecurityString NationalityCode;
    SecurityString NativeCityCode;
    SecurityString ResidenceAdminDivision;
    SecurityString ChineseAccentCode;
    SecurityString JobCategory;
    SecurityString AccompanyNumber;
    SecurityString SkinColor;
    SecurityString HairStyle;
    SecurityString HairColor;
    SecurityString FaceStyle;
    SecurityString FacialFeature;
    SecurityString PhysicalFeature;
    SecurityString RespiratorColor;
    SecurityString CapStyle;
    SecurityString CapColor;
    SecurityString GlassStyle;
    SecurityString GlassColor;
    int            IsDriver;
    int            IsForeigner;
    SecurityString PassportType;
    SecurityString ImmigrantTypeCode;
    int            IsSuspectedTerrorist;
    SecurityString SuspectedTerroristNumber;
    int            IsCriminalInvolved;
    SecurityString CriminalInvolvedSpecilisationCode;
    SecurityString BodySpeciallMark;
    SecurityString CrimeMethod;
    SecurityString CrimeCharacterCode;
    SecurityString EscapedCriminalNumber;
    int            IsDetainees;
    SecurityString DetentionHouseCode;
    SecurityString DetaineesIdentity;
    SecurityString DetaineesSpecialIdentity;
    SecurityString MemberTypeCode;
    int            IsVictim;
    SecurityString VictimType;
    SecurityString InjuredDegree;
    SecurityString CorpseConditionCode;
    int            IsSuspiciousPerson;
    int            Attitude;
    double         Similaritydegree;
    SecurityString EyebrowStyle;
    SecurityString NoseStyle;
    SecurityString MustacheStyle;
    SecurityString LipStyle;
    SecurityString WrinklePouch;
    SecurityString AcneStain;
    SecurityString FreckleBirthmark;
    SecurityString ScarDimple;
    SecurityString OtherFeature;
    security_subimage_infos_t SubImageList;
} security_face_t;
typedef SecurityArray<security_face_t> security_faces_t;

/**
 * @Struct   security_file_info_t
 * @Brief    FileInfo
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
typedef struct _security_file_info {
    SecurityString FileID;
    SecurityInfoType InfoKind;
    SecurityString Source;
    SecurityString FileName;
    SecurityString StoragePath;
    SecurityString FileHash;
    SecurityString FileFormat;
    SecurityString Title;
    SecurityString SecurityLevel;
    SecurityString SubmiterName;
    SecurityString SubmiterOrg;
    SecurityString EntryTime;
    int            FileSize;
} security_file_info_t;
typedef SecurityArray<security_file_info_t>                 security_file_infos_t;

/**
 * @Struct   security_person_t
 * @Brief
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
typedef struct _security_person_t {
    SecurityString PersionID;
    SecurityInfoType InfoKind;
    SecurityString SourceID;
    SecurityString DeviceID;
    int            LeftTopX;
    int            LeftTopY;
    int            RightBtmX;
    int            RightBtmY;
    SecurityString LocationMarkTime;
    SecurityString PersonAppearTime;
    SecurityString PersonDisAppearTime;
    SecurityString IDType;
    int            IDNumber;
    SecurityString Name;
    SecurityString UsedName;
    SecurityString Alias;
    SecurityString GenderCode;
    int            AgeUpLimit;
    int            AgeLowerLimit;
    SecurityString EthicCode;
    SecurityString NationalityCode;
    SecurityString NativeCityCode;
    SecurityString ResidenceAdminDivision;
    SecurityString ChineseAccentCode;
    SecurityString PersonOrg;
    SecurityString JobCategory;
    int            AccompanyNumber;
    int            HeightUpLimit;
    int            HeightLowerLimit;
    int            BodyType;
    SecurityString SkinColor;
    SecurityString HairStyle;
    SecurityString HairColor;
    SecurityString Gesture;
    SecurityString Status;
    SecurityString FaceStyle;
    SecurityString FacialFeature;
    SecurityString PhysicalFeature;
    SecurityString BodyFeature;
    SecurityString HabitualMovement;
    SecurityString Behavior;
    SecurityString BehaviorDescription;
    SecurityString Appendant;
    SecurityString AppendantDescription;
    SecurityString UmbrellaColor;
    SecurityString RespiratorColor;
    SecurityString CapStyle;
    SecurityString CapColor;
    SecurityString GlassStyle;
    SecurityString GlassColor;
    SecurityString ScarfColor;
    SecurityString BagStyle;
    SecurityString BagColor;
    SecurityString CoatStyle;
    SecurityString CoatLength;
    SecurityString CoatColor;
    SecurityString TrousersStyle;
    SecurityString TrousersColor;
    SecurityString TrousersLen;
    SecurityString ShoesStyle;
    SecurityString ShoesColor;
    int            IsDriver;
    int            IsForeigner;
    SecurityString PassportType;
    SecurityString ImmigrantTypeCode;
    int            IsSuspectedTerrorist;
    SecurityString SuspectedTerroristNumber;
    int            IsCriminalInvolved;
    SecurityString CriminalInvolvedSpecilisationCode;
    SecurityString BodySpeciallMark;
    SecurityString CrimeMethod;
    SecurityString CrimeCharacterCode;
    SecurityString EscapedCriminalNumber;
    int            IsDetainees;
    SecurityString DetentionHouseCode;
    SecurityString DetaineesIdentity;
    SecurityString DetaineesSpecialIdentity;
    SecurityString MemberTypeCode;
    int            IsVictim;
    SecurityString VictimType;
    SecurityString InjuredDegree;
    SecurityString CorpseConditionCode;
    int            IsSuspiciousPerson;
    security_subimage_infos_t SubImageList;
} security_person_t;
typedef SecurityArray<security_person_t> security_persons_t;

/**
 * @Struct   security_motorvehicle_t
 * @Brief    机动车对象
 * @DateTime 2018/8/10 11:43:12
 * @Modify   2018/8/10 11:43:18
 * @Author   Nanuns
 */
typedef struct _security_motorvehicle_t {
    SecurityString MotorVehicleID;
    SecurityInfoType InfoKind;
    SecurityString SourceID;
    SecurityString TollgateID;
    SecurityString DeviceID;
    SecurityString StorageUrl1;
    SecurityString StorageUrl2;
    SecurityString StorageUrl3;
    SecurityString StorageUrl4;
    SecurityString StorageUrl5;
    int            LeftTopX;
    int            LeftTopY;
    int            RightBtmX;
    int            RightBtmY;
    SecurityString MarkTime;
    SecurityString AppearTime;
    SecurityString DisappearTime;
    int            LaneNo;
    SecurityString HasPlate;
    SecurityString PlateClass;
    SecurityString PlateColor;
    SecurityString PlateNo;
    SecurityString PlateNoAttach;
    SecurityString PlateDescribe;
    SecurityString IsDecked;
    SecurityString IsAltered;
    SecurityString IsCovered;
    SpeedType      Speed;
    SecurityString Direction;
    SecurityString DrivingStatusCode;
    int            UsingPropertiesCode;
    SecurityString VehicleClass;
    SecurityString VehicleBrand;
    SecurityString VehicleModel;
    SecurityString VehicleStyles;
    int            VehicleLength;
    int            VehicleWidth;
    int            VehicleHeight;
    SecurityString VehicleColor;
    SecurityString VehicleColorDepth;
    SecurityString VehicleHood;
    SecurityString VehicleTrunk;
    SecurityString VehicleWheel;
    SecurityString WheelPrintedPattern;
    SecurityString VehicleWindow;
    SecurityString VehicleRoof;
    SecurityString VehicleDoor;
    SecurityString SideOfVehicle;
    SecurityString CarOfVehicle;
    SecurityString RearviewMirror;
    SecurityString VehicleChassis;
    SecurityString VehicleShielding;
    SecurityString FilmColor;
    SecurityString IsModified;
    SecurityString HitMarkInfo;
    SecurityString VehicleBodyDesc;
    SecurityString VehicleFrontItem;
    SecurityString DescOfFrontItem;
    SecurityString VehicleRearItem;
    SecurityString DescOfRearItem;
    int            NumOfPassenger;
    SecurityString PassTime;
    SecurityString NameOfPassedRoad;
    SecurityString IsSuspicious;
    int            Sunvisor;
    int            SafetyBelt;
    int            Calling;
    SecurityString PlateReliability;
    SecurityString PlateCharReliability;
    SecurityString BrandReliability;
    security_subimage_infos_t SubImageList;
} security_motorvehicle_t;
typedef SecurityArray<security_motorvehicle_t> security_motorvehicles_t;

/**
 * @Struct   security_nonmotorvehicle_t
 * @Brief    非机动车对象
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Nanuns
 */
typedef struct _security_nonmotorvehicle_t {
    SecurityString NonMotorVehicleID;
    SecurityInfoType InfoKind;
    SecurityString SourceID;
    SecurityString DeviceID;
    int            LeftTopX;
    int            LeftTopY;
    int            RightBtmX;
    int            RightBtmY;
    SecurityString MarkTime;
    SecurityString AppearTime;
    SecurityString DisappearTime;
    SecurityString HasPlate;
    SecurityString PlateClass;
    SecurityString PlateColor;
    SecurityString PlateNo;
    SecurityString PlateNoAttach;
    SecurityString PlateDescribe;
    SecurityString IsDecked;
    SecurityString IsAltered;
    SecurityString IsCovered;
    SpeedType      Speed;
    SecurityString DrivingStatusCode;
    int            UsingPropertiesCode;
    SecurityString VehicleBrand;
    SecurityString VehicleType;
    int            VehicleLength;
    int            VehicleWidth;
    int            VehicleHeight;
    SecurityString VehicleColor;
    SecurityString VehicleHood;
    SecurityString VehicleTrunk;
    SecurityString VehicleWheel;
    SecurityString WheelPrintedPattern;
    SecurityString VehicleWindow;
    SecurityString VehicleRoof;
    SecurityString VehicleDoor;
    SecurityString SideOfVehicle;
    SecurityString CarOfVehicle;
    SecurityString RearviewMirror;
    SecurityString VehicleChassis;
    SecurityString VehicleShielding;
    int            FilmColor;
    int            IsModified;
    security_subimage_infos_t SubImageList;
} security_nonmotorvehicle_t;
typedef SecurityArray<security_nonmotorvehicle_t> security_nonmotorvehicles_t;

/**
 * @Struct   security_thing_t
 * @Brief    物品对象
 * @DateTime 2018/8/10 13:17:10
 * @Modify   2018/8/10 13:17:13
 * @Author   Nanuns
 */
typedef struct _security_thing_t {
    SecurityString ThingID;
    SecurityInfoType InfoKind;
    SecurityString SourceID;
    SecurityString DeviceID;
    int            LeftTopX;
    int            LeftTopY;
    int            RightBtmX;
    int            RightBtmY;
    SecurityString LocationMarkTime;
    SecurityString AppearTime;
    SecurityString DisappearTime;
    SecurityString Name;
    SecurityString Shape;
    SecurityString Color;
    SecurityString Size;
    SecurityString Material;
    SecurityString Characteristic;
    SecurityString Propertiy;
    SecurityString InvolvedObjectType;
    SecurityString FirearmsAmmunitionType;
    SecurityString ToolTraceType;
    SecurityString EvidenceType;
    SecurityString CaseEvidenceType;
    security_subimage_infos_t SubImageList;
} security_thing_t;
typedef SecurityArray<security_thing_t> security_things_t;

/**
 * @Struct   security_scene_t
 * @Brief    场景对象
 * @DateTime 2018/8/10 13:17:10
 * @Modify   2018/8/10 13:17:13
 * @Author   Nanuns
 */
typedef struct _security_scene_t {
    SecurityString SceneID;
    SecurityInfoType InfoKind;
    SecurityString SourceID;
    SecurityString DeviceID;
    SecurityString BeginTime;
    SecurityString PlaceType;
    SecurityString WeatherType;
    SecurityString SceneDescribe;
    SecurityString SceneType;
    SecurityString RoadAlignmentType;
    int            RoadTerraintype;
    SecurityString RoadSurfaceType;
    SecurityString RoadCoditionType;
    SecurityString RoadJunctionSectionType;
    SecurityString RoadLightingType;
    SecurityString Illustration;
    SecurityString WindDirection;
    SecurityString Illumination;
    SecurityString FieldCondition;
    double         Temperature;
    SecurityString Humidity;
    SecurityString PopulationDensity;
    SecurityString DenseDegree;
    int            Importance;
    security_subimage_infos_t SubImageList;
} security_scene_t;
typedef SecurityArray<security_scene_t> security_scenes_t;

/**
 * @Struct   security_caseinfo_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_caseinfo_t {
    SecurityString CaseID;
    SecurityString CaseLinkMark;
    SecurityString CaseName;
    SecurityString CaseAbstract;
    SecurityString ClueID;
    SecurityString TimeUpLimit;
    SecurityString TimeLowerLimit;
    SecurityString CreateTime;
    SecurityString PlaceCode;
    SecurityString PlaceFullAddress;
    int            SuspectNumber;
    SecurityString WitnessIDs;
    SecurityString CreatorName;
    SecurityString CreatorIDType;
    SecurityString CreatorID;
    SecurityString CreatorOrg;
    LongitudeType  Longitude;
    LatitudeType   Latitude;
    SecurityString EventIDs;
    SecurityString MotorVehicleIDs;
    SecurityString NonMotorVehicleIDs;
    SecurityString PersonIDs;
    SecurityString FaceIDs;
    SecurityString ThingIDs;
    SecurityString FileIDs;
    SecurityString SceneIDs;
    SecurityString RelateCaseIdList;
    SecurityString ParentCaseId;
    int            State;
} security_caseinfo_t;
typedef SecurityArray<security_caseinfo_t>                  security_caseinfos_t;

/**
 * @Struct   security_videoslice_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Nanuns
 */
typedef struct _security_videoslice_t {
    security_videoslice_info_t  VideoSliceInfo;
    security_persons_t          PersonList;
    security_faces_t            FaceList;
    security_motorvehicles_t    MotorVehicleList;
    security_nonmotorvehicles_t NonmotorVehicleList;
    security_things_t           ThingList;
    security_scenes_t           SceneList;
    SecurityString              Data;
} security_videoslice_t;
typedef SecurityArray<security_videoslice_t> security_videoslices_t;

/**
 * @Struct   security_image_t
 * @Brief
 * @DateTime 2018/8/10 11:19:14
 * @Modify   2018/8/10 11:19:20
 * @Author   Nanuns
 */
typedef struct _security_image_t {
    security_image_info_t       ImageInfo;
    security_persons_t          PersonList;
    security_faces_t            FaceList;
    security_motorvehicles_t    MotorVehicleList;
    security_nonmotorvehicles_t NonMotorVehicleList;
    security_things_t           ThingList;
    security_scenes_t           SceneList;
    SecurityString              Data;
} security_image_t;
typedef SecurityArray<security_image_t>                     security_images_t;

/**
 * @Struct   security_file_t
 * @Brief    File
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
typedef struct _security_file {
    security_file_info_t FileInfo;
    security_persons_t PersonList;
    security_faces_t FaceList;
    security_motorvehicles_t MotorVehicleList;
    security_nonmotorvehicles_t NonMotorVehicleList;
    security_things_t ThingList;
    security_scenes_t SceneList;
    SecurityString Data;
} security_file_t;
typedef SecurityArray<security_file_t>                      security_files_t;

/**
 * @Struct   security_case_t
 * @Brief    视频案事件对象
 * @DateTime 2018/8/10 13:28:48
 * @Modify   2018/8/10 13:28:52
 * @Author   Nanuns
 */
typedef struct _security_case_t {
    security_caseinfo_t CaseInfo;
    security_videoslices_t VideoSliceList;
    security_images_t ImageList;
    security_files_t FileList;
    security_persons_t PersonList;
    security_faces_t FaceList;
    security_motorvehicles_t MotorVehicleList;
    security_nonmotorvehicles_t NonMotorVehicleList;
    security_things_t ThingList;
    security_scenes_t SceneList;
} security_case_t;
typedef SecurityArray<security_case_t> security_cases_t;

/**
 * @Struct   security_videolabel_t
 * @Brief    视频图像标签对象
 * @DateTime 2018/8/10 13:39:59
 * @Modify   2018/8/10 13:40:04
 * @Author   Nanuns
 */
typedef struct _security_videolabel_t {
    typedef struct _color_area_t {
        int AreaPosX;
        int AreaPosY;
        int AreaWidth;
        int AreaHeight;
    } color_area_t;
    typedef SecurityArray<color_area_t> color_areas_t;

    typedef struct _target_t {
        int PosX;
        int PosY;
        int Width;
        int Height;
        int Status;
        int SpeedVal;
        int SpeedRad;
    } target_t;
    typedef SecurityArray<target_t> targets_t;

    typedef struct _behavior_analysis_t {
        int            EventLevel;
        SecurityString BehaviorBeginTime;
        SecurityString BehaviorBeginTimeRlt;
        int            BehaviorBeginFrameNoRlt;
        SecurityString BehaviorEndTime;
        SecurityString BehaviorEndTimeRlt;
        int            BehaviorEndFrameNoRlt;
    } behavior_analysis_t;
    //typedef SecurityArray<behavior_analysis_t> behavior_analysiss_t;

    SecurityString VideoLabelID;
    SecurityString EventSort;
    SecurityString EventRuleID;
    SecurityString VideoImageID;
    SecurityString VideoImageUrl;
    SecurityString CameraID;
    SecurityString IVADeviceID;
    SecurityString CreateTimeAbs;
    int            CreateTimeRlt;
    int64_t        CreateFrameNoRlt;
    SecurityString PersonID;
    SecurityString FaceID;
    SecurityString MotorVehicleID;
    SecurityString NonMotorVehicleID;
    SecurityString ThingID;
    SecurityString SceneID;
    SecurityString TargetColor;
    int            ColorCount;
    color_areas_t  ColorAreaSet;
    int            MoveObjectNum;
    targets_t      MoveObjectSet;
    behavior_analysis_t BehaviorAnalysisObject;
    SecurityString ImagePath;
    SecurityString Desc;
    int            TargetNum;
    int            PersonNum;
    int            FaceNum;
    int            VehicleNum;
    int            ThingNum;
    int            TargetDensityAbs;
    int            PersonDensityAbs;
    int            FacenDensityAbs;
    int            VehicleDensityAbs;
    int            ThingDensityAbs;
    int            TargetDensityRlt;
    int            PersonDensityRlt;
    int            FacenDensityRlt;
    int            VehicleDensityRlt;
    int            ThingDensityRlt;
    int            TotalTargetFlowRate;
    int            PersonFlowRate;
    int            VehicleFlowRate;
    int            FlowDirection;
} security_videolabel_t;
typedef SecurityArray<security_videolabel_t>                security_videolabels_t;
/**
 * @Struct   security_videolabel_all_content_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Nanuns
 */
typedef struct _security_videolabel_all_content_t {

} security_videolabel_all_content_t;
typedef SecurityArray<security_videolabel_all_content_t>    security_videolabel_all_contents_t;

/**
 * @Struct   security_analysis_rule_t
 * @Brief    视频图像分析规则对象
 * @DateTime 2018/8/10 13:54:47
 * @Modify   2018/8/10 13:54:50
 * @Author   Nanuns
 */
typedef struct _security_analysis_rule_t {
    typedef struct _point_t {
        int PointX;
        int PointY;
    } point_t;
    typedef SecurityArray<point_t> points_t;

    typedef struct _line_t {
        int Direction;
        points_t PointObjectList;
    } line_t;
    typedef SecurityArray<line_t> lines_t;

    typedef struct _direction_type_t {
        int Direction;
        int TargetType;
    } direction_type_t;
    typedef SecurityArray<direction_type_t> directions_t;

    SecurityString AnalysisRuleID;
    SecurityString VideoImageID;
    SecurityString VideoImageUrl;
    SecurityString CameraID;
    int            Width;
    int            Height;
    int            MinDuration;
    int            LineMinDuration;
    int            LineMaxDuration;
    int            MaxDuration;
    int            LineNum;
    lines_t        LineSet;
    int            PointNum;
    int            PointID;
    points_t       PointSet;
    int            Direction;
    int            ActionType;
    int            BeginPointX;
    int            BeginPointY;
    int            EndPointX;
    int            EndPointY;
    int            DirectionNum;
    directions_t   DirectionSet;
    int            DensityUnit;
} security_analysis_rule_t;
typedef SecurityArray<security_analysis_rule_t>             security_analysis_rules_t;

/**
 * @Struct   security_device_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_device_t {

} security_device_t;
typedef SecurityArray<security_device_t> security_devices_t;

/**
 * @Struct   security_device_status_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_device_status_t {

} security_device_status_t;
typedef SecurityArray<security_device_status_t> security_device_statuss_t;

/**
 * @Struct   security_lane_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_lane_t {
    int            id;
    SecurityString tollgateId;
    int            laneNo;
    SecurityString name;
    SecurityString direction;
    SecurityString desc;
    int            maxSpeed;
    int            cityPass;
    SecurityString apeId;
} security_lane_t;
typedef SecurityArray<security_lane_t> security_lanes_t;

/**
 * @Struct   security_tollgate_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_tollgate_t {

} security_tollgate_t;
typedef SecurityArray<security_tollgate_t> security_tollgates_t;

/**
 * @Struct   security_ape_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_ape_t {

} security_ape_t;
typedef SecurityArray<security_ape_t> security_apes_t;

/**
 * @Struct   security_aps_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_aps_t {

} security_aps_t;
typedef SecurityArray<security_aps_t> security_apss_t;

/**
 * @Struct   security_aps_status_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_aps_status_t {

} security_aps_status_t;
typedef SecurityArray<security_aps_status_t> security_aps_statuss_t;

/**
 * @Struct   security_disposition_t
 * @Brief
 * @DateTime 2018/8/10 14:07:00
 * @Modify   2018/8/10 14:07:05
 * @Author   Nanuns
 */
typedef struct _security_disposition_t {
    SecurityString id;
    SecurityString title;
    SecurityString category;
    SecurityString targetFeature;
    SecurityString targetImageUri;
    int priorityLevel;
    SecurityString applicantName;
    SecurityString applicantInfo;
    SecurityString applicantOrg;
    SecurityString beginTime;
    SecurityString endTime;
    SecurityString createTime;
    int            operateType;
    int            status;
    int            range;
    SecurityString tollgateList;
    SecurityString area;
    SecurityString receiveAddr;
    SecurityString receiveMobile;
    SecurityString reson;
    SecurityString removeOrg;
    SecurityString removePerson;
    SecurityString removeTime;
    SecurityString removeReason;
    security_subimage_infos_t subimageList;
} security_disposition_t;
typedef SecurityArray<security_disposition_t>               security_dispositions_t;

/**
 * @Struct   security_disposition_notification_t
 * @Brief
 * @DateTime 2018/8/10 13:54:47
 * @Modify   2018/8/10 13:54:50
 * @Author   Nanuns
 */
typedef struct _security_disposition_notification_t {
    SecurityString NotificationID;
    SecurityString dispositionId;
    SecurityString title;
    SecurityString triggerTime;
    SecurityString cntObjectId;
    security_person_t person;
    security_motorvehicle_t motorVehicle; // MotorVehicleObject
} security_disposition_notification_t;
typedef SecurityArray<security_disposition_notification_t>  security_disposition_notifications_t;

/**
 * @Struct   security_subscribe_t
 * @Brief
 * @DateTime 2018/8/10 11:20:41
 * @Modify   2018/8/10 11:20:52
 * @Author   Nanuns
 */
typedef struct _security_subscribe_t {
    SecurityString SubscribeID;
    SecurityString title;
    SecurityString detail;
    SecurityString resourceUri;
    SecurityString applicantName;
    SecurityString applicantOrg;
    SecurityString beginTime;
    SecurityString endTime;
    SecurityString receiveAddr;
    int            reportInterval;
    SecurityString reason;
    int            operateType;
    int            status;
    SecurityString cancelOrg;
    SecurityString cancelPerson;
    SecurityString cancelTime;
    SecurityString cancelReson;
} security_subscribe_t;
typedef SecurityArray<security_subscribe_t>                 security_subscribes_t;

/**
 * @Struct   security_subscribe_notification_t
 * @Brief
 * @DateTime 2018/8/10 14:31:34
 * @Modify   2018/8/10 14:31:38
 * @Author   Nanuns
 */
typedef struct _security_subscribe_notification_t {
    SecurityString              id;
    SecurityString              subscribeId;
    SecurityString              title;
    SecurityString              triggerTime;
    SecurityString              infoIds;
    security_cases_t            caseList;
    security_tollgates_t        tollgateList;
    security_lanes_t            laneList;
    security_devices_t          apeList;
    security_device_statuss_t   deviceStautusList;
    security_apss_t             apsList;
    security_aps_statuss_t      apsStatusList;
    security_persons_t          personList;
    security_faces_t            faceList;
    security_motorvehicles_t    motorVehicleList;
    security_nonmotorvehicles_t nonMotorVehicleList;
    security_things_t           thingList;
    security_scenes_t           sceneList;
} security_subscribe_notification_t;
typedef SecurityArray<security_subscribe_notification_t>    security_subscribe_notifications_t;

typedef struct _security_viidserver_t {
    SecurityString id;
    SecurityString serverName;
    SecurityString ipAddr;
    SecurityString ipv6Addr;
    int            port;
    SecurityString upServerId;
    SecurityString subServerId;
    bool           isOnline;
    SecurityString lastOnlineTime;
} security_viidserver_t;
typedef SecurityArray<security_viidserver_t> security_viidservers_t;

typedef struct _security_task_t {

} security_task_t;
typedef SecurityArray<security_task_t>                      security_tasks_t;

typedef struct _security_task_control_t {

} security_task_control_t;
typedef SecurityArray<security_task_control_t>              security_task_controls_t;

typedef struct _attr_condition {
    SecurityString key;
    SecurityString value;
} attr_condition_t;
typedef SecurityArray<attr_condition_t>                     attr_conditions_t;

/**
 * @Struct   security_system_time_t
 * @Brief    SystemTimeObject
 * @DateTime 2018-08-01T10:52:46+0800
 * @Modify   2018-08-01T10:52:46+0800
 * @Author   Nanuns
 */
typedef struct _security_system_time_t {
    SecurityString VIIDServerID;
    SecurityString TimeMode; // 1:网络 2:手动
    SecurityString LocalTime;
    SecurityString TimeZone;
} security_system_time_t;

typedef struct _security_system_status_t {
    SecurityString viidServerId;
    bool           isOnline;
    SecurityString currentTime;
} security_system_status_t;

typedef struct _security_time_server_t {
    int            ntpServerId;
    SecurityString serverName;
    SecurityString ipAddr;
    SecurityString ipv6Addr;
    int            port;
} security_time_server_t;

// ResponseStatusObject
typedef struct _security_response_status_t {
    SecurityString RequestURL;
    int            StatusCode;
    SecurityString StatusString;
    SecurityString Id;
    SecurityString LocalTime;
} security_response_status_t;
// ResponseStatusList
typedef SecurityArray<security_response_status_t> security_response_statuss_t;


#endif
