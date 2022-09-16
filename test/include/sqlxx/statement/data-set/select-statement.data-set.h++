/*!
 * @file select-statement.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_HXX

#include <iterator>
#include <vector>

#include "./select-statement.data-set-element.class.h++"
#include "./select-statement.data-set.00.h++"
#include "./select-statement.data-set.01.h++"
#include "./select-statement.data-set.02.h++"
#include "./select-statement.data-set.03.h++"
#include "./select-statement.data-set.04.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__statement)

BOOST_AUTO_TEST_SUITE(class__SelectStatement)

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectStatement              テスト対象クラス
 * @see sqlxx::closure::SelectStatement::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string() -> std::vector<DataSetElement>
{
    std::vector<std::vector<DataSetElement>> data_set_parts = {
        // clang-format off
        data_set_for_to_string_00(),
        data_set_for_to_string_01(),
        data_set_for_to_string_02(),
        data_set_for_to_string_03(),
        data_set_for_to_string_04()
        // clang-format on
    };

    auto data_set = std::vector<DataSetElement>();
    for (auto && data_set_part : data_set_parts) {
        data_set.insert(
            std::end(data_set),
            std::begin(data_set_part),
            std::end(data_set_part));
    }
    return data_set;
}

BOOST_AUTO_TEST_SUITE_END(/* class__SelectStatement */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__statement */)

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__SELECT_STATEMENT_DATA_SET_HXX */
