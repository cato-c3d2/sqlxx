/*!
 * @file example-00.c++
 *
 * @brief HelloWorld プログラム
 */

#include <iostream>

#include <hello-world++/hello-world.class.h++>

/*!
 * @brief 標準出力に HelloWorld の文言を出力する
 *
 * @return プログラムのリターンコード @n
 *         常に @c 0 を返却する
 */
auto main() -> int
{
    using namespace hello_worldxx;

    HelloWorld const hello_world;
    std::cout << hello_world() << std::endl;
}
