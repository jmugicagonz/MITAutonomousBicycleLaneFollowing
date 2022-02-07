CVPY_TYPE(Algorithm, Ptr<cv::Algorithm>, Ptr, NoBase, 0);
CVPY_TYPE(AsyncArray, Ptr<cv::AsyncArray>, Ptr, NoBase, pyopencv_cv_AsyncArray_AsyncArray);
CVPY_TYPE(FileStorage, Ptr<cv::FileStorage>, Ptr, NoBase, pyopencv_cv_FileStorage_FileStorage);
CVPY_TYPE(FileNode, cv::FileNode, FileNode, NoBase, pyopencv_cv_FileNode_FileNode);
CVPY_TYPE(cuda_GpuMat, Ptr<cv::cuda::GpuMat>, Ptr, NoBase, pyopencv_cv_cuda_cuda_GpuMat_GpuMat);
CVPY_TYPE(cuda_GpuMat_Allocator, Ptr<cv::cuda::GpuMat::Allocator>, Ptr, NoBase, 0);
CVPY_TYPE(cuda_BufferPool, Ptr<cv::cuda::BufferPool>, Ptr, NoBase, 0);
CVPY_TYPE(cuda_HostMem, Ptr<cv::cuda::HostMem>, Ptr, NoBase, pyopencv_cv_cuda_cuda_HostMem_HostMem);
CVPY_TYPE(cuda_Stream, Ptr<cv::cuda::Stream>, Ptr, NoBase, pyopencv_cv_cuda_cuda_Stream_Stream);
CVPY_TYPE(cuda_Event, Ptr<cv::cuda::Event>, Ptr, NoBase, pyopencv_cv_cuda_cuda_Event_Event);
CVPY_TYPE(cuda_TargetArchs, Ptr<cv::cuda::TargetArchs>, Ptr, NoBase, 0);
CVPY_TYPE(cuda_DeviceInfo, Ptr<cv::cuda::DeviceInfo>, Ptr, NoBase, pyopencv_cv_cuda_cuda_DeviceInfo_DeviceInfo);
CVPY_TYPE(TickMeter, Ptr<cv::TickMeter>, Ptr, NoBase, pyopencv_cv_TickMeter_TickMeter);
CVPY_TYPE(KeyPoint, cv::KeyPoint, KeyPoint, NoBase, pyopencv_cv_KeyPoint_KeyPoint);
CVPY_TYPE(DMatch, cv::DMatch, DMatch, NoBase, pyopencv_cv_DMatch_DMatch);
CVPY_TYPE(ocl_Device, cv::ocl::Device, Device, NoBase, pyopencv_cv_ocl_ocl_Device_Device);
CVPY_TYPE(ocl_OpenCLExecutionContext, Ptr<cv::ocl::OpenCLExecutionContext>, Ptr, NoBase, 0);
CVPY_TYPE(UMat, Ptr<cv::UMat>, Ptr, NoBase, pyopencv_cv_UMat_UMat);
CVPY_TYPE(flann_Index, Ptr<cv::flann::Index>, Ptr, NoBase, pyopencv_cv_flann_flann_Index_Index);
CVPY_TYPE(GeneralizedHough, Ptr<cv::GeneralizedHough>, Ptr, Algorithm, 0);
CVPY_TYPE(GeneralizedHoughBallard, Ptr<cv::GeneralizedHoughBallard>, Ptr, GeneralizedHough, 0);
CVPY_TYPE(GeneralizedHoughGuil, Ptr<cv::GeneralizedHoughGuil>, Ptr, GeneralizedHough, 0);
CVPY_TYPE(CLAHE, Ptr<cv::CLAHE>, Ptr, Algorithm, 0);
CVPY_TYPE(Subdiv2D, Ptr<cv::Subdiv2D>, Ptr, NoBase, pyopencv_cv_Subdiv2D_Subdiv2D);
CVPY_TYPE(LineSegmentDetector, Ptr<cv::LineSegmentDetector>, Ptr, Algorithm, 0);
CVPY_TYPE(ml_ParamGrid, Ptr<cv::ml::ParamGrid>, Ptr, NoBase, 0);
CVPY_TYPE(ml_TrainData, Ptr<cv::ml::TrainData>, Ptr, NoBase, 0);
CVPY_TYPE(ml_StatModel, Ptr<cv::ml::StatModel>, Ptr, Algorithm, 0);
CVPY_TYPE(ml_NormalBayesClassifier, Ptr<cv::ml::NormalBayesClassifier>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_KNearest, Ptr<cv::ml::KNearest>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_SVM, Ptr<cv::ml::SVM>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_EM, Ptr<cv::ml::EM>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_DTrees, Ptr<cv::ml::DTrees>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_RTrees, Ptr<cv::ml::RTrees>, Ptr, ml_DTrees, 0);
CVPY_TYPE(ml_Boost, Ptr<cv::ml::Boost>, Ptr, ml_DTrees, 0);
CVPY_TYPE(ml_ANN_MLP, Ptr<cv::ml::ANN_MLP>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_LogisticRegression, Ptr<cv::ml::LogisticRegression>, Ptr, ml_StatModel, 0);
CVPY_TYPE(ml_SVMSGD, Ptr<cv::ml::SVMSGD>, Ptr, ml_StatModel, 0);
CVPY_TYPE(Tonemap, Ptr<cv::Tonemap>, Ptr, Algorithm, 0);
CVPY_TYPE(TonemapDrago, Ptr<cv::TonemapDrago>, Ptr, Tonemap, 0);
CVPY_TYPE(TonemapReinhard, Ptr<cv::TonemapReinhard>, Ptr, Tonemap, 0);
CVPY_TYPE(TonemapMantiuk, Ptr<cv::TonemapMantiuk>, Ptr, Tonemap, 0);
CVPY_TYPE(AlignExposures, Ptr<cv::AlignExposures>, Ptr, Algorithm, 0);
CVPY_TYPE(AlignMTB, Ptr<cv::AlignMTB>, Ptr, AlignExposures, 0);
CVPY_TYPE(CalibrateCRF, Ptr<cv::CalibrateCRF>, Ptr, Algorithm, 0);
CVPY_TYPE(CalibrateDebevec, Ptr<cv::CalibrateDebevec>, Ptr, CalibrateCRF, 0);
CVPY_TYPE(CalibrateRobertson, Ptr<cv::CalibrateRobertson>, Ptr, CalibrateCRF, 0);
CVPY_TYPE(MergeExposures, Ptr<cv::MergeExposures>, Ptr, Algorithm, 0);
CVPY_TYPE(MergeDebevec, Ptr<cv::MergeDebevec>, Ptr, MergeExposures, 0);
CVPY_TYPE(MergeMertens, Ptr<cv::MergeMertens>, Ptr, MergeExposures, 0);
CVPY_TYPE(MergeRobertson, Ptr<cv::MergeRobertson>, Ptr, MergeExposures, 0);
CVPY_TYPE(dnn_DictValue, Ptr<cv::dnn::DictValue>, Ptr, NoBase, pyopencv_cv_dnn_dnn_DictValue_DictValue);
CVPY_TYPE(dnn_Layer, Ptr<cv::dnn::Layer>, Ptr, Algorithm, 0);
CVPY_TYPE(dnn_Net, cv::dnn::Net, Net, NoBase, pyopencv_cv_dnn_dnn_Net_Net);
CVPY_TYPE(dnn_Model, cv::dnn::Model, Model, dnn_Net, pyopencv_cv_dnn_dnn_Model_Model);
CVPY_TYPE(dnn_ClassificationModel, cv::dnn::ClassificationModel, ClassificationModel, dnn_Model, pyopencv_cv_dnn_dnn_ClassificationModel_ClassificationModel);
CVPY_TYPE(dnn_KeypointsModel, Ptr<cv::dnn::KeypointsModel>, Ptr, dnn_Model, pyopencv_cv_dnn_dnn_KeypointsModel_KeypointsModel);
CVPY_TYPE(dnn_SegmentationModel, Ptr<cv::dnn::SegmentationModel>, Ptr, dnn_Model, pyopencv_cv_dnn_dnn_SegmentationModel_SegmentationModel);
CVPY_TYPE(dnn_DetectionModel, cv::dnn::DetectionModel, DetectionModel, dnn_Model, pyopencv_cv_dnn_dnn_DetectionModel_DetectionModel);
CVPY_TYPE(Feature2D, Ptr<cv::Feature2D>, Ptr, NoBase, 0);
CVPY_TYPE(AffineFeature, Ptr<cv::AffineFeature>, Ptr, Feature2D, 0);
CVPY_TYPE(SIFT, Ptr<cv::SIFT>, Ptr, Feature2D, 0);
CVPY_TYPE(BRISK, Ptr<cv::BRISK>, Ptr, Feature2D, 0);
CVPY_TYPE(ORB, Ptr<cv::ORB>, Ptr, Feature2D, 0);
CVPY_TYPE(MSER, Ptr<cv::MSER>, Ptr, Feature2D, 0);
CVPY_TYPE(FastFeatureDetector, Ptr<cv::FastFeatureDetector>, Ptr, Feature2D, 0);
CVPY_TYPE(AgastFeatureDetector, Ptr<cv::AgastFeatureDetector>, Ptr, Feature2D, 0);
CVPY_TYPE(GFTTDetector, Ptr<cv::GFTTDetector>, Ptr, Feature2D, 0);
CVPY_TYPE(SimpleBlobDetector, Ptr<cv::SimpleBlobDetector>, Ptr, Feature2D, 0);
CVPY_TYPE(SimpleBlobDetector_Params, cv::SimpleBlobDetector::Params, Params, NoBase, pyopencv_cv_SimpleBlobDetector_Params_SimpleBlobDetector_Params);
CVPY_TYPE(KAZE, Ptr<cv::KAZE>, Ptr, Feature2D, 0);
CVPY_TYPE(AKAZE, Ptr<cv::AKAZE>, Ptr, Feature2D, 0);
CVPY_TYPE(DescriptorMatcher, Ptr<cv::DescriptorMatcher>, Ptr, Algorithm, 0);
CVPY_TYPE(BFMatcher, Ptr<cv::BFMatcher>, Ptr, DescriptorMatcher, pyopencv_cv_BFMatcher_BFMatcher);
CVPY_TYPE(FlannBasedMatcher, Ptr<cv::FlannBasedMatcher>, Ptr, DescriptorMatcher, pyopencv_cv_FlannBasedMatcher_FlannBasedMatcher);
CVPY_TYPE(BOWTrainer, Ptr<cv::BOWTrainer>, Ptr, NoBase, 0);
CVPY_TYPE(BOWKMeansTrainer, Ptr<cv::BOWKMeansTrainer>, Ptr, BOWTrainer, pyopencv_cv_BOWKMeansTrainer_BOWKMeansTrainer);
CVPY_TYPE(BOWImgDescriptorExtractor, Ptr<cv::BOWImgDescriptorExtractor>, Ptr, NoBase, pyopencv_cv_BOWImgDescriptorExtractor_BOWImgDescriptorExtractor);
CVPY_TYPE(VideoCapture, Ptr<cv::VideoCapture>, Ptr, NoBase, pyopencv_cv_VideoCapture_VideoCapture);
CVPY_TYPE(VideoWriter, Ptr<cv::VideoWriter>, Ptr, NoBase, pyopencv_cv_VideoWriter_VideoWriter);
CVPY_TYPE(UsacParams, cv::UsacParams, UsacParams, NoBase, pyopencv_cv_UsacParams_UsacParams);
CVPY_TYPE(CirclesGridFinderParameters, cv::CirclesGridFinderParameters, CirclesGridFinderParameters, NoBase, pyopencv_cv_CirclesGridFinderParameters_CirclesGridFinderParameters);
CVPY_TYPE(StereoMatcher, Ptr<cv::StereoMatcher>, Ptr, Algorithm, 0);
CVPY_TYPE(StereoBM, Ptr<cv::StereoBM>, Ptr, StereoMatcher, 0);
CVPY_TYPE(StereoSGBM, Ptr<cv::StereoSGBM>, Ptr, StereoMatcher, 0);
CVPY_TYPE(BaseCascadeClassifier, Ptr<cv::BaseCascadeClassifier>, Ptr, Algorithm, 0);
CVPY_TYPE(CascadeClassifier, Ptr<cv::CascadeClassifier>, Ptr, NoBase, pyopencv_cv_CascadeClassifier_CascadeClassifier);
CVPY_TYPE(HOGDescriptor, Ptr<cv::HOGDescriptor>, Ptr, NoBase, pyopencv_cv_HOGDescriptor_HOGDescriptor);
CVPY_TYPE(QRCodeDetector, Ptr<cv::QRCodeDetector>, Ptr, NoBase, pyopencv_cv_QRCodeDetector_QRCodeDetector);
CVPY_TYPE(Stitcher, Ptr<cv::Stitcher>, Ptr, NoBase, 0);
CVPY_TYPE(PyRotationWarper, Ptr<cv::PyRotationWarper>, Ptr, NoBase, pyopencv_cv_PyRotationWarper_PyRotationWarper);
CVPY_TYPE(WarperCreator, Ptr<cv::WarperCreator>, Ptr, NoBase, 0);
CVPY_TYPE(detail_CameraParams, cv::detail::CameraParams, CameraParams, NoBase, 0);
CVPY_TYPE(detail_Timelapser, Ptr<cv::detail::Timelapser>, Ptr, NoBase, 0);
CVPY_TYPE(detail_TimelapserCrop, Ptr<cv::detail::TimelapserCrop>, Ptr, detail_Timelapser, 0);
CVPY_TYPE(detail_Blender, Ptr<cv::detail::Blender>, Ptr, NoBase, 0);
CVPY_TYPE(detail_FeatherBlender, Ptr<cv::detail::FeatherBlender>, Ptr, detail_Blender, pyopencv_cv_detail_detail_FeatherBlender_FeatherBlender);
CVPY_TYPE(detail_MultiBandBlender, Ptr<cv::detail::MultiBandBlender>, Ptr, detail_Blender, pyopencv_cv_detail_detail_MultiBandBlender_MultiBandBlender);
CVPY_TYPE(detail_ExposureCompensator, Ptr<cv::detail::ExposureCompensator>, Ptr, NoBase, 0);
CVPY_TYPE(detail_NoExposureCompensator, Ptr<cv::detail::NoExposureCompensator>, Ptr, detail_ExposureCompensator, 0);
CVPY_TYPE(detail_GainCompensator, Ptr<cv::detail::GainCompensator>, Ptr, detail_ExposureCompensator, pyopencv_cv_detail_detail_GainCompensator_GainCompensator);
CVPY_TYPE(detail_ChannelsCompensator, Ptr<cv::detail::ChannelsCompensator>, Ptr, detail_ExposureCompensator, pyopencv_cv_detail_detail_ChannelsCompensator_ChannelsCompensator);
CVPY_TYPE(detail_BlocksCompensator, Ptr<cv::detail::BlocksCompensator>, Ptr, detail_ExposureCompensator, 0);
CVPY_TYPE(detail_BlocksGainCompensator, Ptr<cv::detail::BlocksGainCompensator>, Ptr, detail_BlocksCompensator, pyopencv_cv_detail_detail_BlocksGainCompensator_BlocksGainCompensator);
CVPY_TYPE(detail_BlocksChannelsCompensator, Ptr<cv::detail::BlocksChannelsCompensator>, Ptr, detail_BlocksCompensator, pyopencv_cv_detail_detail_BlocksChannelsCompensator_BlocksChannelsCompensator);
CVPY_TYPE(detail_ProjectorBase, cv::detail::ProjectorBase, ProjectorBase, NoBase, 0);
CVPY_TYPE(detail_SphericalProjector, cv::detail::SphericalProjector, SphericalProjector, detail_ProjectorBase, 0);
CVPY_TYPE(detail_Estimator, Ptr<cv::detail::Estimator>, Ptr, NoBase, 0);
CVPY_TYPE(detail_HomographyBasedEstimator, Ptr<cv::detail::HomographyBasedEstimator>, Ptr, detail_Estimator, pyopencv_cv_detail_detail_HomographyBasedEstimator_HomographyBasedEstimator);
CVPY_TYPE(detail_AffineBasedEstimator, Ptr<cv::detail::AffineBasedEstimator>, Ptr, detail_Estimator, pyopencv_cv_detail_detail_AffineBasedEstimator_AffineBasedEstimator);
CVPY_TYPE(detail_BundleAdjusterBase, Ptr<cv::detail::BundleAdjusterBase>, Ptr, detail_Estimator, 0);
CVPY_TYPE(detail_NoBundleAdjuster, Ptr<cv::detail::NoBundleAdjuster>, Ptr, detail_BundleAdjusterBase, pyopencv_cv_detail_detail_NoBundleAdjuster_NoBundleAdjuster);
CVPY_TYPE(detail_BundleAdjusterReproj, Ptr<cv::detail::BundleAdjusterReproj>, Ptr, detail_BundleAdjusterBase, pyopencv_cv_detail_detail_BundleAdjusterReproj_BundleAdjusterReproj);
CVPY_TYPE(detail_BundleAdjusterRay, Ptr<cv::detail::BundleAdjusterRay>, Ptr, detail_BundleAdjusterBase, pyopencv_cv_detail_detail_BundleAdjusterRay_BundleAdjusterRay);
CVPY_TYPE(detail_BundleAdjusterAffine, Ptr<cv::detail::BundleAdjusterAffine>, Ptr, detail_BundleAdjusterBase, pyopencv_cv_detail_detail_BundleAdjusterAffine_BundleAdjusterAffine);
CVPY_TYPE(detail_BundleAdjusterAffinePartial, Ptr<cv::detail::BundleAdjusterAffinePartial>, Ptr, detail_BundleAdjusterBase, pyopencv_cv_detail_detail_BundleAdjusterAffinePartial_BundleAdjusterAffinePartial);
CVPY_TYPE(detail_ImageFeatures, cv::detail::ImageFeatures, ImageFeatures, NoBase, 0);
CVPY_TYPE(detail_MatchesInfo, cv::detail::MatchesInfo, MatchesInfo, NoBase, 0);
CVPY_TYPE(detail_FeaturesMatcher, Ptr<cv::detail::FeaturesMatcher>, Ptr, NoBase, 0);
CVPY_TYPE(detail_BestOf2NearestMatcher, Ptr<cv::detail::BestOf2NearestMatcher>, Ptr, detail_FeaturesMatcher, pyopencv_cv_detail_detail_BestOf2NearestMatcher_BestOf2NearestMatcher);
CVPY_TYPE(detail_BestOf2NearestRangeMatcher, Ptr<cv::detail::BestOf2NearestRangeMatcher>, Ptr, detail_BestOf2NearestMatcher, pyopencv_cv_detail_detail_BestOf2NearestRangeMatcher_BestOf2NearestRangeMatcher);
CVPY_TYPE(detail_AffineBestOf2NearestMatcher, Ptr<cv::detail::AffineBestOf2NearestMatcher>, Ptr, detail_BestOf2NearestMatcher, pyopencv_cv_detail_detail_AffineBestOf2NearestMatcher_AffineBestOf2NearestMatcher);
CVPY_TYPE(detail_SeamFinder, Ptr<cv::detail::SeamFinder>, Ptr, NoBase, 0);
CVPY_TYPE(detail_NoSeamFinder, Ptr<cv::detail::NoSeamFinder>, Ptr, detail_SeamFinder, 0);
CVPY_TYPE(detail_PairwiseSeamFinder, Ptr<cv::detail::PairwiseSeamFinder>, Ptr, detail_SeamFinder, 0);
CVPY_TYPE(detail_VoronoiSeamFinder, Ptr<cv::detail::VoronoiSeamFinder>, Ptr, detail_PairwiseSeamFinder, 0);
CVPY_TYPE(detail_DpSeamFinder, Ptr<cv::detail::DpSeamFinder>, Ptr, detail_SeamFinder, pyopencv_cv_detail_detail_DpSeamFinder_DpSeamFinder);
CVPY_TYPE(detail_GraphCutSeamFinder, Ptr<cv::detail::GraphCutSeamFinder>, Ptr, NoBase, pyopencv_cv_detail_detail_GraphCutSeamFinder_GraphCutSeamFinder);
CVPY_TYPE(BackgroundSubtractor, Ptr<cv::BackgroundSubtractor>, Ptr, Algorithm, 0);
CVPY_TYPE(BackgroundSubtractorMOG2, Ptr<cv::BackgroundSubtractorMOG2>, Ptr, BackgroundSubtractor, 0);
CVPY_TYPE(BackgroundSubtractorKNN, Ptr<cv::BackgroundSubtractorKNN>, Ptr, BackgroundSubtractor, 0);
CVPY_TYPE(KalmanFilter, Ptr<cv::KalmanFilter>, Ptr, NoBase, pyopencv_cv_KalmanFilter_KalmanFilter);
CVPY_TYPE(DenseOpticalFlow, Ptr<cv::DenseOpticalFlow>, Ptr, Algorithm, 0);
CVPY_TYPE(SparseOpticalFlow, Ptr<cv::SparseOpticalFlow>, Ptr, Algorithm, 0);
CVPY_TYPE(FarnebackOpticalFlow, Ptr<cv::FarnebackOpticalFlow>, Ptr, DenseOpticalFlow, 0);
CVPY_TYPE(VariationalRefinement, Ptr<cv::VariationalRefinement>, Ptr, DenseOpticalFlow, 0);
CVPY_TYPE(DISOpticalFlow, Ptr<cv::DISOpticalFlow>, Ptr, DenseOpticalFlow, 0);
CVPY_TYPE(SparsePyrLKOpticalFlow, Ptr<cv::SparsePyrLKOpticalFlow>, Ptr, SparseOpticalFlow, 0);
CVPY_TYPE(GStreamingCompiled, cv::GStreamingCompiled, GStreamingCompiled, NoBase, pyopencv_cv_GStreamingCompiled_GStreamingCompiled);
CVPY_TYPE(GScalar, cv::GScalar, GScalar, NoBase, pyopencv_cv_GScalar_GScalar);
CVPY_TYPE(GInferInputs, cv::GInferInputs, GInferInputs, NoBase, pyopencv_cv_GInferInputs_GInferInputs);
CVPY_TYPE(GInferOutputs, cv::GInferOutputs, GInferOutputs, NoBase, pyopencv_cv_GInferOutputs_GInferOutputs);
CVPY_TYPE(gapi_GNetPackage, cv::gapi::GNetPackage, GNetPackage, NoBase, pyopencv_cv_gapi_gapi_GNetPackage_GNetPackage);
CVPY_TYPE(gapi_GKernelPackage, cv::gapi::GKernelPackage, GKernelPackage, NoBase, 0);
CVPY_TYPE(GComputation, Ptr<cv::GComputation>, Ptr, NoBase, pyopencv_cv_GComputation_GComputation);
CVPY_TYPE(GFrame, cv::GFrame, GFrame, NoBase, pyopencv_cv_GFrame_GFrame);
CVPY_TYPE(GMat, cv::GMat, GMat, NoBase, pyopencv_cv_GMat_GMat);
CVPY_TYPE(gapi_ie_PyParams, cv::gapi::ie::PyParams, PyParams, NoBase, 0);
CVPY_TYPE(GCompileArg, cv::GCompileArg, GCompileArg, NoBase, 0);
CVPY_TYPE(GProtoArg, cv::GProtoArg, GProtoArg, NoBase, 0);
CVPY_TYPE(GProtoInputArgs, cv::GProtoInputArgs, GProtoInputArgs, NoBase, 0);
CVPY_TYPE(GProtoOutputArgs, cv::GProtoOutputArgs, GProtoOutputArgs, NoBase, 0);
CVPY_TYPE(GRunArg, cv::GRunArg, GRunArg, NoBase, 0);
CVPY_TYPE(GMetaArg, cv::GMetaArg, GMetaArg, NoBase, 0);
CVPY_TYPE(gapi_wip_IStreamSource, Ptr<cv::gapi::wip::IStreamSource>, Ptr, NoBase, 0);
