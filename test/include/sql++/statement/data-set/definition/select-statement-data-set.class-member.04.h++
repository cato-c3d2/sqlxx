/*!
 * @file select-statement-data-set.class-member.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_04_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_04_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/identifier/column-identifier.class.h++>
#include <sql++/identifier/table-identifier.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "../select-statement-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace statement
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    using sqlxx::ColumnIdentifier;
    using sqlxx::FromClause;
    using sqlxx::SelectClause;
    using sqlxx::SelectStatement;
    using sqlxx::TableIdentifier;

    /*!
     * @brief  データセットを返却する
     *
     * データパターン : その他
     *
     * @return データセット
     *
     * @see sqlxx::statement::SelectStatement              テスト対象クラス
     * @see sqlxx::statement::SelectStatement::to_string() テスト対象メンバ関数
     */
    auto SelectStatementDataSet::for_some_test_case_04()
        -> std::vector<SelectStatementDataSetElement>
    {
        // clang-format off
        return {
            // _64
            {
                // [条件]
                // + select_closure : 未指定
                // + from_closure   : 未指定
                SelectStatement {},
                // [期待結果] to_string メンバ関数
                ""
            },
            // _65
            {
                // [条件]
                // + select_closure :
                //     + columns  : 未指定
                // + from_closure : 未指定
                SelectStatement {
                    SelectClause {}
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _66
            {
                // [条件]
                // + select_closure : 未指定
                // + from_closure   :
                //     + table      : 未指定
                SelectStatement {}.from(FromClause {}),
                // [期待結果] to_string メンバ関数
                ""
            },
            // _67
            {
                // [条件]
                // + select_closure :
                //     + columns : 未指定
                // + from_closure :
                //     + table   : 未指定
                SelectStatement {
                    SelectClause {},
                    FromClause {}
                },
                // [期待結果] to_string メンバ関数
                ""
            },
            // _68
            {
                // [条件]
                // + select_closure :
                //     + columns[0] :
                //         + name       : 不適格
                //         + as_closure : 不適格
                //     + columns[1] :
                //         + name       : 不適格
                //         + as_closure : 不適格
                // + from_closure :
                //     + table :
                //         + name       : 不適格
                //         + as_closure : 不適格
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { " " }.as({ "," }),
                        ColumnIdentifier { "." }.as({ ";" })
                    }},
                    FromClause {
                        TableIdentifier { "\'" }.as({ "\\" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }
} // namespace statement
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_04_HXX */
