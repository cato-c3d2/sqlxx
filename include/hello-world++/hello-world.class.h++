/*!
 * @file hello-world.class.h++
 */

#ifndef HELLO_WORLDXX__HELLO_WORLD_CLASS_HXX
#define HELLO_WORLDXX__HELLO_WORLD_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

namespace hello_worldxx
{
    /*!
     * @brief HelloWorld 演算を行う関数オブジェクト
     */
    class HelloWorld
    {
    public:
        /*! @brief HelloWorld 文言のデフォルト値 */
        static const std::string default_message;

        /*!
         * @brief 関数オブジェクトを生成する
         *
         * @param[in] message HelloWorld 文言
         */
        HelloWorld(std::string message = HelloWorld::default_message);

        /*!
         * @brief 関数呼び出し演算
         *
         * HelloWorld の文言を返却する. @n
         *
         * @return HelloWorld の文言
         */
        auto operator()() const -> std::string;

    private:
        std::string _message;
    };
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition
//
////////////////////////////////////////////////////////////////////////////////

namespace hello_worldxx
{
    const std::string HelloWorld::default_message = "Hello, World.";

    HelloWorld::HelloWorld(std::string const message) : _message { message }
    {}

    auto HelloWorld::operator()() const -> std::string
    {
        return this->_message;
    }
}

#endif /* HELLO_WORLDXX__HELLO_WORLD_CLASS_HXX */
