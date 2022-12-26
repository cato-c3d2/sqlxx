/*!
 * @file column.data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/specification/column.class.h++>

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Column)

using sqlxx::specification::Column;

/*!
 * @brief データセットの要素
 *
 * テスト対象のオブジェクトと生成される SQL 文字列の期待結果を保持する.
 */
struct DataSetElement
{
    /*! @brief テスト対象オブジェクト */
    Column column;

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
    return out << "{ column : \"" << data_set_element.column
               << "\", expectation_of_to_string : \""
               << data_set_element.expectation_of_to_string << "\" }";
}

BOOST_AUTO_TEST_SUITE_END(/* class__Column */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__COLUMN_DATA_SET_ELEMENT_CLASS_HXX */