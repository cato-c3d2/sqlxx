/*!
 * @file from-closure-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/closure/from-closure.class.h++>

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__FromClosure)

using sqlxx::closure::FromClosure;

/*!
 * @brief データセットの要素
 *
 * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する.
 */
struct FromClosureDataSetElement
{
    /*! @brief テスト対象オブジェクト */
    FromClosure from_closure;

    /*! @brief @c empty メンバ関数の期待結果 */
    bool expectation_of_empty;

    /*! @brief @c to_string メンバ関数の期待結果 */
    std::string expectation_of_to_string;
};

/**
 * @brief ストリーム出力演算
 *
 * @param[in] out              出力ストリーム
 * @param[in] data_set_element データセットの要素
 *
 * @return 出力ストリーム
 */
auto operator<<(
    std::ostream & out, FromClosureDataSetElement const & data_set_element)
    -> std::ostream &
{
    return out << "{ from_closure : \"" << data_set_element.from_closure
               << "\", expectation_of_empty : \""
               << data_set_element.expectation_of_empty
               << "\", expectation_of_to_string : \""
               << data_set_element.expectation_of_to_string << "\" }";
}

BOOST_AUTO_TEST_SUITE_END(/* class__FromClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__FROM_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX */
