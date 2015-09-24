
#ifndef __AP_HAL_LINUX_RCOUTPUT_RASPILOT_H__
#define __AP_HAL_LINUX_RCOUTPUT_RASPILOT_H__

#include "AP_HAL_Linux.h"

class Linux::LinuxRCOutput_Raspilot : public AP_HAL::RCOutput {
    void     init(void* machtnichts);
    void     set_freq(uint32_t chmask, uint16_t freq_hz);
    uint16_t get_freq(uint8_t ch);
    void     enable_ch(uint8_t ch);
    void     disable_ch(uint8_t ch);
    void     write(uint8_t ch, uint16_t period_us);
    void     write(uint8_t ch, uint16_t* period_us, uint8_t len);
    uint16_t read(uint8_t ch);
    void     read(uint16_t* period_us, uint8_t len);

    void     set_safety_pwm(uint32_t chmask, uint16_t period_us);
    void     set_failsafe_pwm(uint32_t chmask, uint16_t period_us);
    bool     force_safety_on(void);
    void     force_safety_off(void);

private:
    void reset();
    void _update(void);

    uint32_t _last_update_timestamp;
    uint16_t _frequency;
    uint16_t _period_us[8];
};

#endif // __AP_HAL_LINUX_RCOUTPUT_RASPILOT_H__
