/*!
 * @file column-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/identifier/column.class.h++>

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__Column)

using sqlxx::identifier::Column;

/*!
 * @brief データセットの要素
 *
 * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する.
 */
struct ColumnDataSetElement
{
    /*! @brief テスト対象オブジェクト */
    Column column;

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
    std::ostream & out, ColumnDataSetElement const & data_set_element)
    -> std::ostream &
{
    return out << "{ column : \"" << data_set_element.column
               << "\", expectation_of_empty : \""
               << data_set_element.expectation_of_empty
               << "\", expectation_of_to_string : \""
               << data_set_element.expectation_of_to_string << "\" }";
}

BOOST_AUTO_TEST_SUITE_END(/* class__Column */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_DATA_SET_ELEMENT_CLASS_HXX */
