/*!
 * @file hello-world.class.test-case.h++
 */

#ifndef TEST__INCLUDE__HELLO_WORLDXX__HELLO_WORLD_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__HELLO_WORLDXX__HELLO_WORLD_CLASS_TEST_CASE_HXX

#include <hello-world++/hello-world.class.h++>

BOOST_AUTO_TEST_SUITE(namespace__hello_worldxx)

using namespace hello_worldxx;

BOOST_AUTO_TEST_SUITE(class__HelloWorld)

/*!
 * @brief テストパターン :
 *        デフォルト引数で @c HelloWorld オブジェクトを生成し,
 *        関数呼び出し演算を行う
 *
 * @see hello_worldxx::HelloWorld
 * @see hello_worldxx::HelloWorld::HelloWorld
 * @see hello_worldxx::HelloWorld::operator()()
 */
BOOST_AUTO_TEST_CASE(default_message)
{
    HelloWorld const hello_world;

    // 関数呼び出し演算の戻り値が期待結果と一致すること
    BOOST_CHECK_EQUAL(hello_world(), "Hello, World.");
}

/*!
 * @brief テストパターン :
 *        HelloWorld 文言を指定した @c HelloWorld オブジェクトを生成し,
 *        関数呼び出し演算を行う
 *
 * @see hello_worldxx::HelloWorld
 * @see hello_worldxx::HelloWorld::HelloWorld
 * @see hello_worldxx::HelloWorld::operator()()
 */
BOOST_AUTO_TEST_CASE(specified_message)
{
    HelloWorld const hello_world { "hello, world." };

    // 関数呼び出し演算の戻り値が期待結果と一致すること
    BOOST_CHECK_EQUAL(hello_world(), "hello, world.");
}

BOOST_AUTO_TEST_SUITE_END(/* class__HelloWorld */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__hello_worldxx */)

#endif /* TEST__INCLUDE__HELLO_WORLDXX__HELLO_WORLD_CLASS_TEST_CASE_HXX */
