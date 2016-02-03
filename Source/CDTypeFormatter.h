// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-2019 Steve Nygard.


@class CDType, CDTypeController;
#import "CDTypeController.h"

@interface CDTypeFormatter : NSObject<CDTypeControllerDelegate>

@property (weak) CDTypeController *typeController;

@property (assign) NSUInteger baseLevel;
@property (assign) BOOL shouldExpand;
@property (assign) BOOL shouldAutoExpand;
@property (assign) BOOL shouldShowLexing;

- (NSString *)formatVariable:(NSString *)name type:(CDType *)type typeName:(NSMutableString *)typeName isTemplate:(BOOL *)isTemplate;
- (NSString *)formatVariable:(NSString *)name type:(CDType *)type;
- (NSString *)formatMethodName:(NSString *)name typeString:(NSString *)typeString;

- (NSString *)typedefNameForStructure:(CDType *)structureType level:(NSUInteger)level;

- (void)formattingDidReferenceClassName:(NSString *)name;
- (void)formattingDidReferenceProtocolNames:(NSArray *)names;

- (void)typeController:(CDTypeController *)typeController didReferenceClassName:(NSString *)name;
- (void)typeController:(CDTypeController *)typeController didReferenceProtocolNames:(NSArray *)names;

@end
