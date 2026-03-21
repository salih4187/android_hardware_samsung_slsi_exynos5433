#ifndef EXYNOS_VIRTUAL_DISPLAY_MODULE_H
#define EXYNOS_VIRTUAL_DISPLAY_MODULE_H

#include "ExynosVirtualDisplay.h"

class ExynosVirtualDisplayModule : public ExynosVirtualDisplay {
    public:
        ExynosVirtualDisplayModule(struct exynos5_hwc_composer_device_1_t *pdev);
        ~ExynosVirtualDisplayModule();

        // void setWFDOutputResolution(unsigned int width, unsigned int height, unsigned int disp_w, unsigned int disp_h);
        // void setPriContents(hwc_display_contents_1_t* contents);
        // void ExynosVirtualDisplayModule::isDeconExtWbSupported(hwc_layer_1 *param_1,uint param_2)
        // int ExynosVirtualDisplayModule::isDeconExtWbSupported(hwc_layer_1 * __unused param_1,uint __unused param_2)
        // void ExynosVirtualDisplayModule::setSinkBufferUsage(ExynosVirtualDisplayModule *this)

        virtual int32_t getDisplayAttributes(const uint32_t attribute, uint32_t config);
};

enum {
    HWC_DISPLAY_COMPOSITION_TYPE = 0,
    HWC_DISPLAY_GLES_FORMAT,
    HWC_DISPLAY_SINK_BQ_FORMAT,
    HWC_DISPLAY_SINK_BQ_USAGE,
    HWC_DISPLAY_SINK_BQ_WIDTH,
    HWC_DISPLAY_SINK_BQ_HEIGHT
};

#endif
