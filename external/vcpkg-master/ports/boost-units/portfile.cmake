# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/units
    REF boost-${VERSION}
    SHA512 2d7709f51ad9051850f02b20191b4652990f4898d5b07e8d6fc26186a077c520626467186b412a04b73712e2ff760aa0be069aa15e9800f731ba5cf0d4ad2c90
    HEAD_REF master
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)