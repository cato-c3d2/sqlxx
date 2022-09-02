include ./configuration.mk

include_home  = ./include/
build_options = $(CXXFLAGS) -I $(include_home)

.PHONY : all
all : clean format build test compare-example document

.PHONY : build
build : build/example-00.exe

build/example-00.exe : ./example/example-00.c++
	$(CXX) $< -o $@ $(build_options)
    # NOTE 自動変数が展開され, 下記のコマンドが評価される :
    #      $(CXX) ./example/example-00.c++ -o build/example-00.exe $(build_options)
    #
    #      自動変数の意味 :
    #      $@ ... ターゲットファイル名
    #      $< ... 最初の依存ファイル名

.PHONY : clean
clean :
	$(RM) ./build/*.exe

.PHONY : compare-example
compare-example : compare-example-00

# サンプルコードの期待結果(テキストファイル)と実行結果(標準出力)を比較し,
# 差異があれば標準エラー出力にリダイレクトするユーザ定義関数
run_and_compare_result = diff -u $(1) <($(2)) 1>&2

.PHONY : compare-example-00
compare-example-00 : ./build/example-00.exe
	$(call run_and_compare_result, ./example/output/example-00.txt, $<)
    # NOTE 自動変数が展開され, 下記のコマンドが実行される :
    #      $(call run_and_compare_result, ./example/output/example-00.txt, ./build/example-00.exe)

################################################################################
# document (Doxygen)
################################################################################

.PHONY : document
document : document-all

.PHONY : document-all
document-all : document-clean document-build

.PHONY : document-build
document-build :
	doxygen > /dev/null
    # NOTE doxygen コマンドの標準出力は量が多いため破棄する.
    #      無論, 標準エラー出力は破棄しない.
    #      ドキュメントコメントが不足している場合は,
    #      doxygen コマンドの warning として標準エラー出力に出力される.

.PHONY : document-clean
document-clean :
	$(RM) -r ./document/html/*

################################################################################
# format (clang-format)
################################################################################

.PHONY : format
format :
	find -type f -name "*.c++" -o -name "*.h++" | xargs clang-format -i

################################################################################
# test (Boost.Test)
################################################################################

.PHONY : test
test :
	cd ./test/ && $(MAKE)
