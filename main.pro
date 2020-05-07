TEMPLATE = subdirs

SUBDIRS += \
    QColorContrastTest\
    example

# set dependencies
example.depends = QColorContrastTest
