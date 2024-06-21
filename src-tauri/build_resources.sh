#!/usr/bin/env sh

######################################################################
# @author      : karlsassie (karlsasssie@gmail.com)
# @file        : build_resources
# @created     : Tuesday May 14, 2024 21:31:37 CEST
#
# @description : 
######################################################################


cross build --manifest-path lib/cli/Cargo.toml --features socket-can --release --target=armv7-unknown-linux-gnueabihf

mkdir -p xcompl
rm -f xcompl/*

cp lib/cli/target/armv7-unknown-linux-gnueabihf/release/canzero-cli xcompl/canzero-cli-armv7-unknown-linux-gnueabihf

