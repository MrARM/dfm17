#ifndef SI4063_H
#define SI4063_H


#include "stm32f1xx_hal.h"

#define RADIO_CS_Pin GPIO_PIN_2
#define RADIO_CS_GPIO_Port GPIOB

// Functions
void SI4X6X_init(uint32_t ref_freq, uint8_t tcxo);
void SI4X6X_deinit(uint8_t tcxo);
void SI4X6X_rx_CTS(uint8_t * rx_buffer, uint8_t len);
void SI4X6X_check_CTS(void);
void SI4X6X_setup_pins(uint8_t gpio0, uint8_t gpio1, uint8_t gpio2, uint8_t gpio3, uint8_t nirq, uint8_t sdo);
void SI4X6X_change_state(uint8_t state);
void SI4X6X_start_TX(uint8_t channel);
void SI4X6X_get_part_info(uint8_t * buffer);
void SI4X6X_get_func_info(uint8_t * buffer);
uint16_t SI4X6X_get_temperature(void);
void SI4X6X_set_frequency(uint32_t frequency, uint32_t ref_freq);
void SI4X6X_set_frequency_deviation(uint32_t deviation);
void SI4X6X_set_frequency_offset(uint32_t offset);
void SI4X6X_set_modulation(uint8_t mod, uint8_t async);
void SI4X6X_set_data_rate(uint32_t data_rate, uint8_t txosr);
void SI4X6X_set_PA_mode(uint8_t pa_sel, uint8_t pa_mode);
void SI4X6X_set_power_level(uint8_t level);
void SI4X6X_set_filter_coefficients(void);
void SI4X6X_tx_CW_blips(uint32_t count, uint16_t length_ms, uint32_t frequency, uint32_t ref_freq, uint16_t modem_freq_offset);
void SI4X6X_tx_FSK_rtty(uint8_t * packet, uint8_t length, uint16_t baud, uint32_t frequency,
						uint32_t ref_freq, uint16_t modem_freq_dev, uint16_t modem_freq_offset);
void SI4X6X_tx_GFSK_aprs(uint8_t * bitstream, uint16_t length, uint32_t frequency, uint32_t ref_freq, uint16_t modem_freq_offset);


#endif // SI4063_H
