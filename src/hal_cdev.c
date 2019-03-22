#include "gpio_nif.h"


#include <fcntl.h>
#include <stdint.h>

#include "hal_cdev.h"

size_t hal_priv_size() {
  return 0;
}

int hal_load(void *hal_priv) {
  return 0;
}

void hal_unload(void *hal_priv) {
}

int hal_open_gpio(struct gpio_pin *pin, char *error_str, ErlNifEnv *env) {
  return 0;
}

void hal_close_gpio(struct gpio_pin *pin) {
}

int hal_read_gpio(struct gpio_pin *pin) {
  return 0;
}

int hal_write_gpio(struct gpio_pin *pin, int value, ErlNifEnv *env) {
  return 0;
}

int hal_apply_direction(struct gpio_pin *pin) {
  (void) pin;
  return 0;
}

int hal_apply_interrupts(struct gpio_pin *pin, ErlNifEnv *env) {
  (void) pin;
  return 0;
}

int hal_apply_pull_mode(struct gpio_pin *pin) {
  (void) pin;
  return 0;
}

ERL_NIF_TERM hal_info(ErlNifEnv *env, void *hal_priv, ERL_NIF_TERM info)
{
    enif_make_map_put(env, info, enif_make_atom(env, "name"), enif_make_atom(env, "cdev"), &info);

    (void) hal_priv;
    return info;
}





