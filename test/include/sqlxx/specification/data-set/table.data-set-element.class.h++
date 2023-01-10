/*!
 * @file table.data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__TABLE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__TABLE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/specification/table.class.h++>

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__Table)

using sqlxx::specification::Table;

/*!
 * @brief データセットの要素
 *
 * テスト対象のオブジェクトと生成される SQL 文字列の期待結果を保持する.
 */
struct DataSetElement
{
    /*! @brief テスト対象オブジェクト */
    Table table;

    /*! @brief 空判定の期待結果 */
    bool expectation_of_empty;

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
    return out << "{ table : \"" << data_set_element.table
               << "\", expectation_of_empty : \""
               << data_set_element.expectation_of_empty
               << "\", expectation_of_to_string : \""
               << data_set_element.expectation_of_to_string << "\" }";
}

BOOST_AUTO_TEST_SUITE_END(/* class__Table */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__TABLE_DATA_SET_ELEMENT_CLASS_HXX */
