//
//  BABCropperView.h
//  Pods
//
//  Created by Bryn Bodayle on April/17/2015.
//
//

#import <UIKit/UIKit.h>

@interface BABCropperView : UIView

@property (nonatomic, assign) CGSize cropSize;
@property (nonatomic, strong) UIImage *image;
@property (readonly, nonatomic, strong) UIImageView *imageView;
@property (readonly, nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIBezierPath *cropMaskPath;
@property (nonatomic, strong) UIView *cropMaskView;
@property (nonatomic, readonly) UIView *borderView;
@property (nonatomic, assign) CGFloat cropDisplayScale; //defaults to 1.0f
@property (nonatomic, assign) UIOffset cropDisplayOffset; //defaults to UIOffsetZero
@property (nonatomic, assign) BOOL cropsImageToCircle; // defaults to NO
@property (nonatomic, assign) BOOL leavesUnfilledRegionsTransparent; // defaults to NO
@property (nonatomic, assign) BOOL allowsNegativeSpaceInCroppedImage; //defaults to NO
@property (nonatomic, assign) BOOL startZoomedToFill; // defaults to NO

/**
 Default 0.0 keeps legacy and scrollView.maximumZoomScale is set to BABCropperViewMaximumZoomScale = 4.0

 Positive value defines what image upscale (resulting to pixelation) is allowed.
 E.g. value of 1 ensures that the cropped image will be 1:1 comapred to the source image
*/
@property (nonatomic, assign) CGFloat maximumImageUpscale; // defaults to 0

/**
 Defines maximum allowed size of the cropped image compared to wanted cropSize.

 Default value of 1.0 ensures any cropped image will be exactly equal to croppedSize.

 Value of 2.0 allows the croped image to be maximum 2x bigger then requested cropSize.

 The cropped size can be expressed like: min(sourceSize, scale(cropSize, maximumImageOversize))
*/
@property (nonatomic, assign) CGFloat maximumCropOversize; // defaults to 1

- (void)renderCroppedImage:(void (^)(UIImage *croppedImage, CGRect cropRect))completionBlock;

@end
