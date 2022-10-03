# ----------------------------
# Makefile Options
# ----------------------------

NAME = CSRIII
ICON = icon.png
DESCRIPTION = "Calculator Street Racing III"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
