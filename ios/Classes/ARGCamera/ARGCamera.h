#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <ARGear/ARGear.h>
#import "GLView.h"

#define DEFAULT_FRAMERATE 30

NS_ASSUME_NONNULL_BEGIN

@protocol ARGCameraDelegate <NSObject>
- (void)didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
               fromConnection:(AVCaptureConnection *)connection;

@optional
- (void)cameraDisplayStart;
@end


@interface ARGCamera : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate, AVCaptureMetadataOutputObjectsDelegate>

@property (nonatomic, unsafe_unretained) id <ARGCameraDelegate> _Nullable delegate;

@property (nonatomic, assign) BOOL isDisplaying;
@property (nonatomic, assign) ARGMediaRatio currentRatio;

@property (nonatomic, strong) AVCaptureSession *captureSession;
@property (nonatomic, strong) NSString *sessionPreset;              // 169: High, 43: Photo, 11: Photo
@property (nonatomic, assign) AVCaptureDevicePosition currentCameraPosition;
@property (nonatomic, strong) AVCaptureDevice *device;
@property (nonatomic, strong) AVCaptureDeviceInput *deviceInput;
@property (nonatomic, strong) dispatch_queue_t sessionQueue;
@property (nonatomic, strong) dispatch_queue_t videoDataOutputQueue;
@property (nonatomic, strong) AVCaptureConnection *videoConnection;
@property (nonatomic, readwrite) AVCaptureVideoOrientation videoOrientation;

- (void)setupCamera;
- (void)startCamera;

- (void)toggleCamera:(void (^_Nullable)(void))completion;
- (void)changeCameraRatio:(ARGMediaRatio)ratio :(void (^_Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
