#ifndef SI4063_H
#define SI4063_H


#include "stm32f1xx_hal.h"

#define pRADIO_CS_Pin GPIO_PIN_2
#define pRADIO_CS_GPIO_Port GPIOB
#define pRADIO_SDN_Pin GPIO_PIN_3
#define pRADIO_SDN_GPIO_Port GPIOC
#define pRADIO_GPIO2_Pin GPIO_PIN_0
#define pRADIO_GPIO2_GPIO_Port GPIOD
#define pRADIO_GPIO3_Pin GPIO_PIN_4
#define pRADIO_GPIO3_GPIO_Port GPIOA

void SI4063_setup_pins(uint8_t gpio0, uint8_t gpio1, uint8_t gpio2, uint8_t gpio3, uint8_t nirq, uint8_t sdo);
void SI4063_change_state(uint8_t state);
void SI4063_rx_CTS(uint8_t * rx_buffer, uint8_t len);
void SI4063_start_TX(uint8_t channel);
void SI4063_set_frequency(uint32_t frequency, uint32_t ref_freq);
void SI4063_set_frequency_deviation(uint32_t deviation);
void SI4063_set_frequency_offset(uint32_t offset);
void SI4063_set_modulation(uint8_t mod, uint8_t async);
void SI4063_set_data_rate(uint32_t data_rate, uint8_t txosr);
void SI4063_set_PA_mode(uint8_t pa_sel, uint8_t pa_mode);
void SI4063_set_power_level(uint8_t level);
void SI4063_set_filter_coefficients(void);

void SI4063_init(uint32_t ref_freq, uint8_t tcxo, SPI_HandleTypeDef *hspi);
void SI4063_deinit(uint8_t tcxo);
void SI4063_tx_CW_blips(uint32_t count, uint16_t length_ms, uint32_t frequency, uint32_t ref_freq, uint16_t modem_freq_offset);
	// TODO: Other modes that require a timer
//void tx_FSK_rtty(uint8_t * packet, uint8_t length, uint16_t baud, uint32_t frequency,
//							uint32_t ref_freq, uint16_t modem_freq_dev, uint16_t modem_freq_offset);
//void tx_GFSK_aprs(uint8_t * bitstream, uint16_t length, uint32_t frequency, uint32_t ref_freq, uint16_t modem_freq_offset);
uint16_t SI4063_get_temperature(void);
void SI4063_get_part_info(uint8_t * buffer);
void SI4063_get_func_info(uint8_t * buffer);
//void SI4X6X_check_CTS(void);

#endif // SI4063_H
