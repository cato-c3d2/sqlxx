/*!
 * @file column-identifier-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_IDENTIFIER_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_IDENTIFIER_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/identifier/column-identifier.class.h++>

namespace sqlxx::test
{
inline namespace
{
    using sqlxx::identifier::ColumnIdentifier;

    /*!
     * @brief データセットの要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する.
     */
    struct ColumnIdentifierDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        ColumnIdentifier column;

        /*!
         * @brief @c empty メンバ関数の期待結果
         */
        bool expectation_of_empty;

        /*!
         * @brief @c to_string メンバ関数の期待結果
         */
        std::string expectation_of_to_string;
    };

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] data_set_element データセットの要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream &                         out,
        ColumnIdentifierDataSetElement const & data_set_element)
        -> std::ostream &
    {
        return out << "{ column : \"" << data_set_element.column
                   << "\", expectation_of_empty : \""
                   << data_set_element.expectation_of_empty
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string << "\" }";
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__COLUMN_IDENTIFIER_DATA_SET_ELEMENT_CLASS_HXX */
