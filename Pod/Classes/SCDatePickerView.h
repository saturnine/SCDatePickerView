//
//  SCDatePickerView.h
//  SCDatePickerView
//
//  Created by Schubert Cardozo on 08/07/14.
//  Copyright (c) 2014 Schubert. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SCDatePickerViewFlowLayout.h"
#import "SCDatePickerViewHeader.h"
#import "SCDatePickerViewCell.h"

typedef NS_ENUM(NSInteger, SCDatePickerVieWStyle) {
    SCDatePickerViewStyleContinous,
    SCDatePickerViewStylePaginated,
    SCDatePickerViewStyleContinousWithRangeSelection
};


@class SCDatePickerView;

@protocol SCDatePickerViewDelegate <NSObject>

@optional

- (CGFloat)heightForMonthHeaderInDatePickerView:(SCDatePickerView *)datePickerView;

- (UIColor *)datePickerView:(SCDatePickerView *)datePickerView selectedDateColorForDate:(NSDate *)date;
- (UIColor *)datePickerView:(SCDatePickerView *)datePickerView enabledDateColorForDate:(NSDate *)date;
- (UIColor *)datePickerView:(SCDatePickerView *)datePickerView disabledDateColorForDate:(NSDate *)date;
- (UIColor *)datePickerView:(SCDatePickerView *)datePickerView invalidDateColorForDate:(NSDate *)date;

- (UIView *)datePickerView:(SCDatePickerView *)datePickerView selectedBackgroundViewForDate:(NSDate *)date withFrame:(CGRect)frame;

- (UIImage *)previousMonthImageForDatePickerView:(SCDatePickerView *)datePickerView;
- (UIImage *)nextMonthImageForDatePickerView:(SCDatePickerView *)datePickerView;

- (void)datePickerView:(SCDatePickerView *)datePickerView didSelectDate:(NSDate *)date;
- (void)datePickerView:(SCDatePickerView *)datePickerView didSelectDateRangeFrom:(NSDate *)fromDate to:(NSDate *)toDate;

@end

@interface SCDatePickerView : UIView<UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@property (nonatomic, weak) IBOutlet id<SCDatePickerViewDelegate> delegate;

// customization properties
@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endDate;
@property (nonatomic, strong) NSDate *selectedDate;
@property (nonatomic, strong) NSDate *selectedEndDate;
@property (nonatomic, assign) int currentMonthOffset;

// FIXME -- switch to use delegate methods
@property (nonatomic, strong) UIFont *headerFont;
@property (nonatomic, strong) UIFont *dayOfWeekFont;
@property (nonatomic, strong) UIFont *dateFont;
@property (nonatomic, strong) UIFont *selectedDateFont;
@property (nonatomic, strong) NSDateFormatter *dateFormatter;
@property (nonatomic, strong) NSDateFormatter *monthYearFormatter;

@property (nonatomic, assign) SCDatePickerVieWStyle style;

- (id)initWithFrame:(CGRect)frame style:(SCDatePickerVieWStyle)style;
//- (void)selectDate:(NSDate *)date;
//- (void)selectDateRangeFromDate:(NSDate *)fromDate toDate:(NSDate *)toDate;

@end