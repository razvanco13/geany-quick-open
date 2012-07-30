#! /usr/bin/env python
# encoding: utf-8

def options(ctx):
	ctx.load('compiler_c')

def configure(ctx):
	ctx.load('compiler_c')  # for pkg-config
	ctx.check_cfg(
			package='gtk+-2.0',
			uselib_store='GTK',
			args=['gtk+-2.0 >= 2.18.0', '--cflags', '--libs'],
			msg='Checking for gtk+-2.0')
	ctx.check_cfg(
			package='geany',
			uselib_store='GEANY',
			args=['geany >= 1.21', '--cflags', '--libs'],
			msg='Checking for geany')

def build(bld):
	bld.shlib(
			source='plugin.c',
			target='geanyquickopen',
			use=['GEANY', 'GTK'],
			install_path='${LIBPATH_GEANY}/geany/')
