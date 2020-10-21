/**
 * @File     gat1400_category.h
 * @brief
 * @DateTime 2018/2/4 10:21:23
 * @Author   Nanuns
 */
#ifndef __GAT1400_CATEGORY_H_
#define __GAT1400_CATEGORY_H_

 /**
  * @Enum     SecurityCaptureDirection
  * @Brief
  * @DateTime 2018-08-11T10:38:04+0800
  * @Modify   2018-08-11T10:38:04+0800
  * @Author   Nanuns
  */
enum class SecurityInfoType {
    Other = 0,
    Auto = 1,
    Manual = 2
};

/**
 * @Enum     SecurityCaptureDirection
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityCaptureDirection {
    Front = 0,
    Tail  = 1
};
/**
 * @Enum     SecurityTollgateStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityTollgateStatus {
    Working = 1,
    Stop    = 2,
    Other   = 9
};
/**
 * @Enum     SecurityTollgatePurpose
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityTollgatePurpose {
    Security = 80,
    Traffic  = 81,
    Other    = 82
};
/**
 * @Enum     SecurityLaneCityPass
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityLaneCityPass {
    Enter = 1,
    Away  = 2,
    None  = 3,
    Mix   = 4
};
/**
 * @Enum     SecurityVideoSliceAudioFlag
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVideoSliceAudioFlag {
    WithoutAudio = 0,
    WithAudio    = 1
};
/**
 * @Enum     SecurityVideoSliceProcFlag
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVideoSliceProcFlag {
    NoProcess = 0,
    Processed = 1
};
/**
 * @Enum     SecurityImageProcFlag
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityImageProcFlag {
    NoProcess = 0,
    Processed = 1
};
/**
 * @Enum     SecurityCommonStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityCommonStatus {
    No     = 0,
    Yes    = 1,
    Unknow = 2
};
/**
 * @Enum     SecurityFaceAttitude
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceAttitude {
    Normal          = 1,
    LittleUp        = 2,
    LittelDown      = 3,
    LeftLittleSide  = 4,
    LeftSide        = 5,
    LeftFull        = 6,
    RightLittleSide = 7,
    RightSide       = 8,
    RightFull       = 9
};
/**
 * @Enum     SecurityFaceEyebrowStyle
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceEyebrowStyle {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7,
    Style8 = 8,
    Style9 = 9
};
/**
 * @Enum     SecurityFaceNoseStyle
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceNoseStyle {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7,
    Style8 = 8,
    Style9 = 9,
    Style10 = 10
};
/**
 * @Enum     SecurityFaceMustacheStyle
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceMustacheStyle {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7
};
/**
 * @Enum     SecurityLipStyle
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityLipStyle {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7,
    Style8 = 8,
    Style9 = 9,
    Style10 = 10
};
/**
 * @Enum     SecurityFaceWrinklePouch
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceWrinklePouch {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7,
    Style8 = 8,
    Style9 = 9,
    Style10 = 10,
    Style11 = 11,
    Style12 = 12
};
/**
 * @Enum     SecurityFaceAcneStain
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceAcneStain {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7
};
/**
 * @Enum     SecurityFaceFreckleBirthmark
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceFreckleBirthmark {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7
};
/**
 * @Enum     SecurityFaceScarDimple
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceScarDimple {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3
};
/**
 * @Enum     SecurityFaceOtherFeature
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityFaceOtherFeature {
    Style1 = 1,
    Style2 = 2,
    Style3 = 3,
    Style4 = 4,
    Style5 = 5,
    Style6 = 6,
    Style7 = 7,
    Style8 = 8,
    Style9 = 9,
    Style10 = 10,
    Style11 = 11
};
/**
 * @Enum     SecurityVehiclePlateColor
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVehiclePlateColor {
    Black  = 0,
    White  = 1,
    Yellow = 2,
    Blue   = 3,
    Green  = 4
};
/**
 * @Enum     SecurityVehicleSunvisor
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVehicleSunvisor {
    No = 0,
    Yes = 1
};
/**
 * @Enum     SecurityVehicleSafetyBelt
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVehicleSafetyBelt {
    No = 0,
    Yes = 1
};

typedef SecurityCommonStatus SecurityVehicleModified;
/**
 * @Enum     SecurityVehicleFilmColor
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVehicleFilmColor {
    dark  = 0,
    light = 1,
    none  = 2
};
/**
 * @Enum     SecurityCaseStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityCaseStatus {
    NewCase                 = 0,
    Checkin                 = 1,
    Resolved                = 2,
    ResolvedForCheck        = 3,
    FullResolved            = 4,
    FullResolvedForCheck    = 5,
    ComposedForCheck        = 6,
    CanceledForCheck        = 7,
    FullResolvedAndArchived = 8,
    ComposedAndArchived     = 9,
    CanceledAndArchived     = 10
};
/**
 * @Enum     SecurityVideoSliceTargetStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityVideoSliceTargetStatus {
    First = 0,
    Always = 1,
    Disappear = 2
};
/**
 * @Enum     SecurityEventLevel
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityEventLevel {
    Notice    = 0,
    Warn      = 1,
    FatalWarn = 2,
    Other
};
/**
 * @Enum     SecurityTargetDensity
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityTargetDensity {
    VerySparse = 0,
    Sparse     = 1,
    Dense      = 2,
    VeryDense  = 3
};
/**
 * @Enum     SecurityTriggerDirection
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityTriggerDirection {
    LeftToRight = 0,
    RightToLeft = 1,
    UpToDown    = 2,
    DownToUp    = 3,
    Any         = 4,
    NoOrder
};
/**
 * @Enum     SecurityActionType
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityActionType {
    EnterArea       = 0,
    LeaveArea       = 1,
    AppearInArea    = 2,
    DisappearInArea = 3,
    InArea          = 4,
    Other
};
/**
 * @Enum     SecurityTargetType
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityTargetType {
    Person          = 1,
    Face            = 2,
    MotorVehicle    = 3,
    NonMotorVehicle = 4,
    Thing           = 5,
    Scene           = 6
};
/**
 * @Enum     SecurityDensityUnit
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityDensityUnit {
    Rank = 0,
    Percent = 1,
    Count = 2,
    Other
};
/**
 * @Enum     SecurityTargetFeature
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityTargetFeature {
    KeyValuePair        = 1,
    KeyFromPropertyType = 2,
    Fuzzy               = 3,
    Expression          = 4
};
/**
 * @Enum     SecurityDispositionPriorityLevel
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityDispositionPriorityLevel {
    Level1 = 1,
    Level2 = 2,
    Level3 = 3
};
/**
 * @Enum     SecurityDispositionOperateType
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityDispositionOperateType {
    Disposition   = 0,
    UnDisposition = 1
};
/**
 * @Enum     SecurityDispositionStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityDispositionStatus {
    Doing   = 0,
    Cancel  = 1,
    Expired = 2,
    None    = 9
};
/**
 * @Enum     SecurityDispositionRange
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityDispositionRange {
    Tollgate = 1,
    Area     = 2
};
/**
 * @Enum     SecuritySubscribeOperateType
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecuritySubscribeOperateType {
    Subscribe = 0,
    Cancel = 1
};
/**
 * @Enum     SecuritySubscribeStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecuritySubscribeStatus {
    Doing = 0,
    Canceled = 1,
    Expired = 2,
    None = 9
};
/**
 * @Enum     SecurityResponseStatus
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityResponseStatus {
    Success = 0,
    OtherError = 1,
    DeviceBusy = 2,
    DeviceError = 3,
    InvalidOperation = 4,
    InvalidXmlFormat = 5,
    InvalidXmlContent = 6,
    InvalidJsonFormat = 7,
    InvalidJsonContent = 8,
    Reboot = 9
};
/**
 * @Enum     SecurityColorType
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityColorType {
    Block   = 1,
    White   = 2,
    Gray    = 3,
    Red     = 4,
    Blue    = 5,
    Yellow  = 6,
    Orange  = 7,
    Brown   = 8,
    Green   = 9,
    Purple  = 10,
    Cyan    = 11,
    Pink    = 12,
    Clarity = 13,
    Other   = 99,
};
/**
 * @Enum     SecuritySecretLevel
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecuritySecretLevel {
    TOP      = 1,
    Most     = 2,
    Very     = 3,
    Secret   = 4,
    Internal = 5,
    Public   = 6,
    Other    = 7
};
/**
 * @Enum     SecurityQualityGrade
 * @Brief
 * @DateTime 2018-08-11T10:38:04+0800
 * @Modify   2018-08-11T10:38:04+0800
 * @Author   Nanuns
 */
enum class SecurityQualityGrade {
    Awful   = 1,
    Bad     = 2,
    Common  = 3,
    good    = 4,
    perfect = 5
};

#define SECURITY_TOLLGATE_TYPE_NATION    "10"
#define SECURITY_TOLLGATE_TYPE_NATIVE    "20"
#define SECURITY_TOLLGATE_TYPE_CITY      "30"
#define SECURITY_TOLLGATE_TYPE_INCITY    "31"
#define SECURITY_TOLLGATE_TYPE_COUNTY    "40"
#define SECURITY_TOLLGATE_TYPE_INCOUNTY  "41"
#define SECURITY_TOLLGATE_TYPE_OTHERS    "99"


//=========================================================================================================================//

//=========================================================================================================================//


#endif
