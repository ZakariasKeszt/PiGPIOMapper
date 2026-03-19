#ifndef PIGPIOMAPPER_H
#define PIGPIOMAPPER_H


typedef enum{
	GPIO0,
	GPIO1,
	GPIO2,
	GPIO3,
	GPIO4,
	GPIO5,
	GPIO6,
	GPIO7,
	GPIO8,
	GPIO9,
	GPIO10,
	GPIO11,
	GPIO12,
	GPIO13,
	GPIO14,
	GPIO15,
	GPIO16,
	GPIO17,
	GPIO18,
	GPIO19,
	GPIO20,
	GPIO21,
	GPIO22,
	GPIO23,
	GPIO24,
	GPIO25,
	GPIO26,
	GPIO27
}rp1_gpio_select_t;

typedef enum{
    HIGH,
    LOW
}gpio_output_t;

typedef struct gpio_handle_s gpio_handle_t;
typedef struct rio_handle_s rio_handle_t;
typedef struct rp1_handle_s rp1_handle_t;

rp1_handle_t* init_gpio(void);
gpio_handle_t* create_gpio_pin(rp1_handle_t* rp1_handle, rp1_gpio_select_t gpio);
int set_gpio_output(gpio_handle_t* gpio_handle, gpio_output_t output);

#endif /* PIGPIOMAPPER_H */
