# Roopad

A simple, handwired, 17 key macro-pad concealed as a numpad, using an Arduino Pro Micro.

In addition to 17 Cherry keys and an Arduino you also need:

 * 1 LED to display numlock state
 * 1 reed switch to put between RST and GND
 * 1 3D printed case [like this](https://www.thingiverse.com/thing:1699785)
 * 4 RGB LED

The keyboard has the following 5 Layers:
 * Numpad (default)
 * RGB Settings (LT on NMLCK)
 * Media-Keys (LT on 0)
 * Mouse (LT on ,)
 * Text functions (Backspace, Delete + Space) (LT on Enter)

* Keyboard Maintainer: [Nils Uliczka](https://github.com/darookee)
* Hardware Supported: Handwired
* Hardware Availability:

Make example for this keyboard (after setting up your build environment):

    make roopad:default

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.
