/*!
 * @file select-statement-data-set.class-member.04.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DETAIL__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_04_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DETAIL__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_04_HXX

#include <vector>

#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>
#include <sql++/identifier/column-identifier.class.h++>
#include <sql++/identifier/table-identifier.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "../select-statement-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
{
    using sqlxx::closure::FromClosure;
    using sqlxx::closure::SelectClosure;
    using sqlxx::identifier::ColumnIdentifier;
    using sqlxx::identifier::TableIdentifier;
    using sqlxx::statement::SelectStatement;

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
                    SelectClosure {}
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
                SelectStatement {}.from(FromClosure {}),
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
                    SelectClosure {},
                    FromClosure {}
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
                    SelectClosure {{
                        ColumnIdentifier { " " }.as({ "," }),
                        ColumnIdentifier { "." }.as({ ";" })
                    }},
                    FromClosure {
                        TableIdentifier { "\'" }.as({ "\\" })
                    }
                },
                // [期待結果] to_string メンバ関数
                ""
            }
        };
        // clang-format on
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DETAIL__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_04_HXX */
