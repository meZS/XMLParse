//
//  ViewController.m
//  XMLDictionary
//
//  Created by peng on 2017/6/5.
//  Copyright © 2017年 peng. All rights reserved.
//

#import "ViewController.h"
#import "XMLDictionary.h"
@interface ViewController ()<NSXMLParserDelegate>
@property(nonatomic,strong)NSXMLParser *paser;
@property(nonatomic,strong)NSMutableArray *dataList;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Skin" ofType:@"xml"];
    NSData *data = [[NSData alloc] initWithContentsOfFile:path];
    
    self.paser = [[NSXMLParser alloc] initWithData:data];
    self.paser.delegate = self;
    NSError *error = nil;
    NSDictionary *dic = [XMLDictionary dictionaryForXMLData:data error:&error];
    NSLog(@"输出字典结果：== %@",dic);
}
- (NSMutableArray *)dataList{
    if (!_dataList) {
        _dataList = [[NSMutableArray alloc] initWithCapacity:0];
    }
    return _dataList;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end
