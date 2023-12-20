include ../configuration.mk

include_home  = ../include/
build_options = $(CXXFLAGS) -I $(include_home)

# ------------------------------------------------------------------------------
# Boost.Test を静的ライブラリとして使用する際のコンパイルオプション
# NOTE Boost.Test をヘッダオンリーライブラリとして使用する場合は,
#      この変数をコメントアウトすればよい
boost_test_options = -l boost_unit_test_framework \
                     -static \
                     -D LINK_BOOST_TEST_AS_STATIC_LIBRARY
# ------------------------------------------------------------------------------

.PHONY : all
all : clean build run

.PHONY : build
build : ./build/sql++.test-module.exe

build/sql++.test-module.exe : ./sql++.test-module.c++
	$(CXX) $< -o $@ $(build_options) $(boost_test_options)
    # NOTE 自動変数が展開され, 下記のコマンドが実行される :
    #      $(CXX) ./sql++.test-module.c++ -o ./build/sql++.test-module.exe $(build_options) $(boost_test_options)

.PHONY : clean
clean :
	$(RM) ./build/*.exe

# ------------------------------------------------------------------------------
# Boost.Test の実行時オプション
#
# Boost.Test の実行時オプションを
# make コマンドのコマンドライン引数として指定できる.
#
# e.g. 実行されるテストケースをフィルタリングする場合 :
#
# ```
# $ make run TEST_RUNTIME_OPTIONS=--run_test=*/class__Column
# ```
#
# refarence :
# https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/boost_test/runtime_config/test_unit_filtering.html
# ------------------------------------------------------------------------------
TEST_RUNTIME_OPTIONS =

.PHONY : run
run : ./build/sql++.test-module.exe
	$< $(TEST_RUNTIME_OPTIONS)
    # NOTE 自動変数が展開され, 下記のコマンドが実行される :
    #      build/sql++.test-module.exe $(TEST_RUNTIME_OPTIONS)
