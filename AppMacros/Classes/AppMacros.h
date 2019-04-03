//
//  AppMacros.h
//  AppMacros
//
//  Created by 姚敦鹏 on 2017/9/11.
//  Copyright © 2017年 Encifang. All rights reserved.
//

#ifndef AppMacros_h
#define AppMacros_h

#pragma mark --
#pragma mark -- 打印设置
/**
 调试
 **/
#ifdef DEBUG
#define ALog(fmt, ...) NSLog(fmt, ##__VA_ARGS__)
//DEBUG  模式下打印日志,当前行
# define DLog(fmt, ...) NSLog((@"[Class:%s]\n" "[Methed:%s]\n" "[Line:%d] \n" fmt), __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define ALog(fmt, ...)
#define DLog(fmt, ...)
#define NSLog(...) {}
#endif


#pragma mark -- 
#pragma mark -- 设备、界面
#define kScreenWidth  [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight [[UIScreen mainScreen] bounds].size.height

#define kViewWidth(view)    (view).frame.size.width
#define kViewHeight(view)   (view).frame.size.height

#define kSelfCtrlWidth      kViewWidth(self.view)
#define kSelfCtrlHeight     kViewHeight(self.view)

#define kSelfViewWidth      kViewWidth(self)
#define kSelfViewHeight     kViewHeight(self)

/** 状态栏 高度 iPhoneX：44 other：20 */
#define kStatusBarH             [[UIApplication sharedApplication] statusBarFrame].size.height

/** iPhone X 系列 */
#define isIphoneXLater          (kStatusBarH != 20)

/** NavigationBar 高度：44 */
#define kNavigationBarH         44
/** 状态栏 加 NavigationBar 高度 iPhoneX：88 other：64  */
#define kStatusAndNavBarH       (kStatusBarH + kNavigationBarH)

/** HomeLineH 高度 iPhoneX:34 other:0 */
#define kHomeLineH              (isIphoneXLater ? 34 : 0)
/** TabBar 高度 iPhoneX:83 other:49 */
#define kTabBarH                (49+kHomeLineH)

/** Tabbar 隐藏状态下 头尾高度 iPhoneX:171 other:113 */
#define kNavHAndTabBarHiddenH    (kStatusAndNavBarH + kHomeLineH)
/** Tabbar 显示状态下 头尾高度 iPhoneX:122 other:64 */
#define kNavHAndTabBarShowH      (kStatusAndNavBarH + kTabBarH)

#define SCREEN_MAX_LENGTH (MAX(kScreenWidth, kScreenHeight))
#define SCREEN_MIN_LENGTH (MIN(kScreenWidth, kScreenHeight))


#define IS_IPHONE_4_OR_LESS (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define IS_IPHONE_5         (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define IS_IPHONE_6         (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_6P        (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
#define IS_IPHONE_7         (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_7P        (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
#define IS_IPHONE_8         (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define IS_IPHONE_8P        (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)

#define kIPHONE_7W 375.0
#define kIPHONE_7H 667.0

//以iphone 7 为主流设置比例的宽、高
#define kScaleW kScreenWidth / kIPHONE_7W
#define kScaleH kScreenWidth / kIPHONE_7H

#define kScaleX(x) x * kScaleW
#define kScaleY(y) y * kScaleH

//比例 间距
#define kScaleMargin kScaleX(10)
//为10 的间距
#define kMargin 10


#pragma mark -- View 坐标(x,y)和宽高(width,height)
#define X(v)                    (v).frame.origin.x
#define Y(v)                    (v).frame.origin.y
#define WIDTH(v)                (v).frame.size.width
#define HEIGHT(v)               (v).frame.size.height
#define BWIDTH(v)               (v).bounds.size.width
#define BHEIGHT(v)              (v).bounds.size.height
#define MinX(v)                 CGRectGetMinX((v).frame)
#define MinY(v)                 CGRectGetMinY((v).frame)

#define MidX(v)                 CGRectGetMidX((v).frame)
#define MidY(v)                 CGRectGetMidY((v).frame)

#define MaxX(v)                 CGRectGetMaxX((v).frame)
#define MaxY(v)                 CGRectGetMaxY((v).frame)


#pragma mark -- 设置 View 圆角 和 边框
#define LayerBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]];\
[View.layer setMasksToBounds:YES] // view圆角


#pragma mark -- View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]



#pragma mark -- 
#pragma mark -- 是否iPad、iphone
#define isPad       (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)


#pragma mark -- 
#pragma mark -- 随机数
//随机数 从 0 开始 Max 最大值
#define kRandTo(Max)            (arc4random_uniform(Max+1))
//随机数 Form 最小值 Max 最大值
#define kRandFormTo(Form,Max)   (Form + kRandTo(Max))


#pragma mark -- 
#pragma mark -- 单例设置

#define KSingleToolH(name) + (instancetype)share##name;

// .m文件
#define KSingleToolM(name) \
static id _instance; \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
\
+ (instancetype)share##name \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return _instance; \
}


#pragma mark -- 
#pragma mark -- 版本比较
/** 当前版本 */
#define kSystemVersion           ([[UIDevice currentDevice] systemVersion])
#define kSystemVersionF          ([[[UIDevice currentDevice] systemVersion] floatValue])
#define kSystemVersionD          ([[[UIDevice currentDevice] systemVersion] doubleValue])

//检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([kSystemVersion compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([kSystemVersion compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([kSystemVersion compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([kSystemVersion compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([kSystemVersion compare:v options:NSNumericSearch] != NSOrderedDescending)

/* 是否大于等于IOS7 */
#define isIOS7              (kSystemVersionF >= 7.0)
/* 是否大于等于IOS8 */
#define isIOS8              (kSystemVersionF >=8.0)
/* 是否大于IOS9 */
#define isIOS9              (kSystemVersionF >=9.0)
/* 是否大于等于某个版本 */
#define isIOS(version)      (kSystemVersionF >= (version))


#pragma mark -- 
#pragma mark --  文件目录
/** 获取temp */
#define kPathTemp       NSTemporaryDirectory()

/** Document 沙河路径 */
#define kPathDocument   [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
/** Cache 沙河路径 */
#define kPathCache      [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]


#pragma mark -- 
#pragma mark --  常见主要单例
#define kApplication        [UIApplication sharedApplication]
#define kAppDelegate        [[UIApplication sharedApplication] delegate]
#define kKeyWindow          [UIApplication sharedApplication].keyWindow
#define kUserDefaults       [NSUserDefaults standardUserDefaults]

#pragma mark -- 
#pragma mark -- 通知相关
#define kNotificationCenter     [NSNotificationCenter defaultCenter]
#define kNOTIF_ADD(SEL, n, o)   [kNotificationCenter addObserver:self selector:@selector(SEL) name:n object:o]
#define kNOTIF_POST(n, o, i)    [kNotificationCenter postNotificationName:n object:o userInfo:i]
#define kNOTIF_REMV(n, o)       [kNotificationCenter removeObserver:self name:n object:o]
#define kNOTIF_REMV_All()       [kNotificationCenter removeObserver:self]


/**
 语法糖
 **/
//弱引用
#define WeakThis(name)  __weak typeof(self) name = self
#define WeakSelf()      __weak typeof(self) weakself = self
#define StrongSelf()    __strong typeof(self) strongself = weakself


//时间戳
#define currentTime [NSString stringWithFormat:@"%ld", (long)[[NSDate date] timeIntervalSince1970]]

//获取当前语言
#define currentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//多语言
#define   locStr(str)   NSLocalizedString(str, nil)

//判断委托响应
#define IS_DELEGATE_RSP_SEL(iDel, iSel) (iDel != nil && [iDel respondsToSelector:@selector(iSel)])

//app名称
#define kAppName [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

//app版本
#define kAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

/** 系统版本号 */
#define kSystemVersion [[UIDevice currentDevice] systemVersion]


#pragma mark -- 
#pragma mark -- 加载图片
#define PNGIMAGEFILE(NAME)      [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"png"]]
#define JPGIMAGEFILE(NAME)      [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:@"jpg"]]
#define IMAGEFILE(NAME, EXT)    [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(NAME) ofType:(EXT)]]
#define IMAGENANED(NAME)        [UIImage imageNamed:NAME］


#pragma mark --
#pragma mark -- 颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)
//随机色
#define RandomColor   [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]

#define hexColorA(rgbValue,a) [UIColor colorWithRed:((float)(((rgbValue) & 0xFF0000) >> 16))/255.0 green:((float)(((rgbValue) & 0xFF00)>>8))/255.0 blue: ((float)((rgbValue) & 0xFF))/255.0 alpha:(a)]

#define hexColor(hex) hexColorA(hex,1.0f)

#define kColor_White            [UIColor whiteColor]
#define kColor_Black            [UIColor blackColor]
#define kColor_Red              [UIColor redColor]
#define kColor_Orange           [UIColor orangeColor]
#define kColor_Yellow           [UIColor yellowColor]
#define kColor_Green            [UIColor greenColor]
#define kColor_Blue             [UIColor blueColor]
#define kColor_DarkGray         [UIColor darkGrayColor]
#define kColor_DarkText         [UIColor darkTextColor]
#define kColor_Gray             [UIColor grayColor]
#define kColor_LightGray        [UIColor lightGrayColor]
#define kColor_LightText        [UIColor lightTextColor]
#define kColor_Clear            [UIColor clearColor]
#define kColor_AppBackGound     RGB(245, 245, 245)
#define kColor_line             RGB(240, 240, 240)



#pragma mark --
#pragma mark -- 字体
/* Font 比例字体 */
#define kScaleSFont(size)   [UIFont systemFontOfSize:size * kScaleW]
#define kScaleBFont(size)   [UIFont boldSystemFontOfSize:size * kScaleW]

#define kSFont(size)        [UIFont systemFontOfSize:size * kScaleW]
#define kBFont(size)        [UIFont boldSystemFontOfSize:size * kScaleW]
#define kFont_NavTitle      kSFont(18)
#define kFont_Title         kSFont(16)
#define kFont_Normal        kSFont(14)
#define kFont_SubTitle      kSFont(12)
#define kFont_Size_10       kSFont(10)
#define kFont_Size_8        kSFont(8)


// 检查字符串是否为空(PS：这里认为nil," ", "\n"均是空)
#define kStringIsEmpty(str)     (str==nil || [str length]==0 || [[str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length] == 0)

#define kArrayIsEmpty(array)    (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)

#define kDictIsEmpty(dic)       (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)

#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))



#pragma mark -
#pragma mark NSNumber

/** int 转 NSNumber */
#define kNUMBER_INT(intValue)        [NSNumber numberWithInt:intValue]
/** float 转 NSNumber */
#define kNUMBER_FLOAT(floatValue)    [NSNumber numberWithFloat:floatValue]
/** double 转 NSNumber */
#define kNUMBER_FLOAT(doubleValue)   [NSNumber numberWithDouble:doubleValue]
/** bool 转 NSNumber */
#define kNUMBER_BOOL(boolValue)      [NSNumber numberWithBool:boolValue]


#pragma mark -
#pragma mark NSString

#define StringFormat(s)     [NSString stringWithFormat:@"%@",s]
#define intToString(s)      [NSString stringWithFormat:@"%d",s]
#define floatToString(s)    [NSString stringWithFormat:@"%f",s]
#define doubleToString(s)   [NSString stringWithFormat:@"%lf",s]
#define varString(var)      [NSString stringWithFormat:@"%s",#var]

#pragma mark --
#pragma mark -- URL
#define UrlFromString(s)    [NSURL URLWithString:s]


#endif /* AppMacros_h */
