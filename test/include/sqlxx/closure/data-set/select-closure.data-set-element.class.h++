/*!
 * @file select-closure.data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/closure/select-closure.class.h++>

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__SelectClosure)

using sqlxx::closure::SelectClosure;

/*!
 * @brief データセットの要素
 *
 * テスト対象のオブジェクトと生成される SQL 文字列の期待結果を保持する.
 */
struct DataSetElement
{
    /*! @brief テスト対象オブジェクト */
    SelectClosure select_closure;

    /*! @brief 生成される SQL 文字列の期待結果 */
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
auto operator<<(std::ostream & out, DataSetElement const & data_set_element)
    -> std::ostream &
{
    return out << "{ select_closure : \"" << data_set_element.select_closure
               << "\", expectation_of_to_string : \""
               << data_set_element.expectation_of_to_string << "\" }";
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX */
