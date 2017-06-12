/*
 #####################################################################
 # File    : XMLDictionary
 # Project :
 # Created : 2017/5/3
 # DevTeam : 51job Development Team
 # Author  : jinfeng.peng
 # Notes   :
 #####################################################################
 ### Change Logs   ###################################################
 #####################################################################
 ---------------------------------------------------------------------
 # Date  :
 # Author:
 # Notes :说明:此文件是有XMLReader修改，修改为我们常用的字典的格式
 #
 #####################################################################
 */
#import <Foundation/Foundation.h>

enum {
    XMLDictionaryOptionsProcessNamespaces           = 1 << 0, // Specifies whether the receiver reports the namespace and the qualified name of an element.
    XMLDictionaryOptionsReportNamespacePrefixes     = 1 << 1, // Specifies whether the receiver reports the scope of namespace declarations.
    XMLDictionaryOptionsResolveExternalEntities     = 1 << 2, // Specifies whether the receiver reports declarations of external entities.
};
typedef NSUInteger XMLDictionaryOptions;

@interface XMLDictionary : NSObject <NSXMLParserDelegate>

+ (NSDictionary *)dictionaryForXMLData:(NSData *)data error:(NSError **)errorPointer;
+ (NSDictionary *)dictionaryForXMLString:(NSString *)string error:(NSError **)errorPointer;
+ (NSDictionary *)dictionaryForXMLData:(NSData *)data options:(XMLDictionaryOptions)options error:(NSError **)errorPointer;
+ (NSDictionary *)dictionaryForXMLString:(NSString *)string options:(XMLDictionaryOptions)options error:(NSError **)errorPointer;

@end
