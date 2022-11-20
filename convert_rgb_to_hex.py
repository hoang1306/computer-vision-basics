# https://www.codespeedy.com/convert-rgb-to-hex-color-code-in-python/

import matplotlib


def rgb_to_hex(rgb):
    return "%02x%02x%02x" % rgb


def hex_to_rgb(val):
    val = val.lstrip('#')
    lv = len(val)
    return tuple(int(val[i:i+lv//3], 16) for i in range(0, lv, lv//3))


if __name__ == "__main__":
    print(rgb_to_hex((225, 225, 220)))
    print(hex_to_rgb('FFFFFF'))

    print(matplotlib.colors.to_hex([0.47, 0.0, 1.0]))
    print(matplotlib.colors.to_hex([0.7, 0.321, 0.3, 0.5], keep_alpha=True))
    print(matplotlib.colors.to_rgb("#aabbcc"))
    print(matplotlib.colors.to_rgb("#ddee9f"))
