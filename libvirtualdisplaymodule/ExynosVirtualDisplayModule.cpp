#include "ExynosVirtualDisplayModule.h"

ExynosVirtualDisplayModule::ExynosVirtualDisplayModule(struct exynos5_hwc_composer_device_1_t *pdev)
    : ExynosVirtualDisplay(pdev)
{
    mGLESFormat = HAL_PIXEL_FORMAT_RGBA_8888;
}

ExynosVirtualDisplayModule::~ExynosVirtualDisplayModule()
{
}

// TODO: Backport this from Prebuilt BSP

/*
void ExynosVirtualDisplayModule::setWFDOutputResolution(unsigned int width, unsigned int height,
        unsigned int disp_w, unsigned int disp_h)
{
    mDisplayWidth = disp_w;
    mWidth = width;
    mHeight = height;
    mXres = width;
    mDisplayHeight = disp_h;
    mYres = height;
}

void ExynosVirtualDisplay::setPriContents(hwc_display_contents_1_t __unused *contents)
{
}

void ExynosVirtualDisplayModule::isDeconExtWbSupported(hwc_layer_1 *param_1,uint param_2)

{
  isDeconExtWbSupported(param_1,param_2);
  return;
}

int ExynosVirtualDisplayModule::isDeconExtWbSupported(hwc_layer_1 * __unused param_1,uint __unused param_2)

{
  uint uVar1;
  int in_r2;
  int iVar2;
  int iVar3;

  if ((*(uint *)(param_2 + 8) & 1) != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
    uVar1 = *(uint *)(iVar3 + 4) | 1;
    goto LAB_000140d6;
  }
  if (*(char *)(param_2 + 0x58) == '\0') {
    iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
    uVar1 = *(uint *)(iVar3 + 4) | 2;
    goto LAB_00014224;
  }
  iVar3 = FUN_000131d8(*(undefined4 *)(param_2 + 0xc));
  if (iVar3 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x1a8) != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
    *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 0x80;
    return 0;
  }
  if (4 < *(int *)(iVar3 + 0x28) - 1U) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
    uVar1 = *(uint *)(iVar3 + 4) | 0x40;
    goto LAB_00014224;
  }
  uVar1 = (uint)(*(float *)(param_2 + 0x20) - *(float *)(param_2 + 0x18));
  if ((uVar1 & 3) != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
    uVar1 = *(uint *)(iVar3 + 4) | 0x10;
    goto LAB_00014224;
  }
  if (((int)uVar1 < 0x20) ||
     (iVar3 = *(int *)(param_2 + 0x30) - *(int *)(param_2 + 0x28), iVar3 < 0x20)) {
LAB_00014228:
    iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
    uVar1 = *(uint *)(iVar3 + 4) | 0x10;
    goto LAB_000140d6;
  }
  iVar2 = *(int *)(param_1 + 300);
  if (iVar2 == 0) {
LAB_0001420e:
    iVar3 = isBlendingSupported(*(int *)(param_2 + 0x14));
    if (iVar3 == 0) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
      uVar1 = *(uint *)(iVar3 + 4) | 0x80;
LAB_00014224:
      *(uint *)(iVar3 + 4) = uVar1;
      return 0;
    }
    iVar2 = isOffscreen((hwc_layer_1 *)param_2,*(int *)(param_1 + 8),*(int *)(param_1 + 0xc));
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_2 + 0x10);
      return iVar3;
    }
    __android_log_print(5,"ExynosVirtualDisplayModule","\tlayer %u: off-screen");
  }
  else if (*(int *)(iVar2 + 0x10) == *(int *)(param_2 + 0x10)) {
    if (((double)(longlong)(int)(*(float *)(iVar2 + 0x20) - *(float *)(iVar2 + 0x18)) /
         (double)(longlong)(*(int *)(iVar2 + 0x30) - *(int *)(iVar2 + 0x28)) !=
         (double)(longlong)(int)uVar1 / (double)(longlong)iVar3) ||
       ((double)(longlong)(int)(*(float *)(iVar2 + 0x24) - *(float *)(iVar2 + 0x1c)) /
        (double)(longlong)(*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x2c)) !=
        (double)(longlong)(int)(*(float *)(param_2 + 0x24) - *(float *)(param_2 + 0x1c)) /
        (double)(longlong)(*(int *)(param_2 + 0x34) - *(int *)(param_2 + 0x2c)))) goto LAB_00014228;
    goto LAB_0001420e;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x34) + in_r2 * 4);
  uVar1 = *(uint *)(iVar3 + 4) | 0x20;
LAB_000140d6:
  *(uint *)(iVar3 + 4) = uVar1;
  return 0;
}

void ExynosVirtualDisplayModule::setSinkBufferUsage(ExynosVirtualDisplayModule *this)

{
  undefined4 uVar1;

  *(undefined4 *)(this + 0xac) = 0x800;
  if (this[0x5a] == (ExynosVirtualDisplayModule)0x0) {
    if (this[0x5b] == (ExynosVirtualDisplayModule)0x0) {
      return;
    }
    uVar1 = 0x2000800;
  }
  else {
    uVar1 = 0x1004800;
  }
  *(undefined4 *)(this + 0xac) = uVar1;
  return;
}

*/

int32_t ExynosVirtualDisplayModule::getDisplayAttributes(const uint32_t attribute, uint32_t config __unused)
{
    switch(attribute) {
        case HWC_DISPLAY_COMPOSITION_TYPE:
            return mCompositionType;
        case HWC_DISPLAY_GLES_FORMAT:
            return mGLESFormat;
        case HWC_DISPLAY_SINK_BQ_FORMAT:
            return HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M;
        case HWC_DISPLAY_SINK_BQ_USAGE:
            return mSinkUsage;
        case HWC_DISPLAY_SINK_BQ_WIDTH:
            if (mDisplayWidth == 0)
                return mWidth;
            return mDisplayWidth;
        case HWC_DISPLAY_SINK_BQ_HEIGHT:
            if (mDisplayHeight == 0)
                return mHeight;
            return mDisplayHeight;
        default:
            ALOGE("unknown display attribute %u", attribute);
            return -EINVAL;
    }
    return 0;
}
