/*!
 * @file select-closure.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_HXX

#include <iterator>
#include <vector>

#include <sql++/closure/select-closure.class.h++>

#include "./select-closure.data-set-element.class.h++"
#include "./select-closure.data-set.00.h++"
#include "./select-closure.data-set.01.h++"
#include "./select-closure.data-set.02.h++"
#include "./select-closure.data-set.03.h++"
#include "./select-closure.data-set.04.h++"
#include "./select-closure.data-set.05.h++"
#include "./select-closure.data-set.06.h++"
#include "./select-closure.data-set.07.h++"
#include "./select-closure.data-set.08.h++"
#include "./select-closure.data-set.09.h++"
#include "./select-closure.data-set.10.h++"
#include "./select-closure.data-set.11.h++"
#include "./select-closure.data-set.12.h++"
#include "./select-closure.data-set.13.h++"
#include "./select-closure.data-set.14.h++"
#include "./select-closure.data-set.15.h++"
#include "./select-closure.data-set.16.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__closure)

BOOST_AUTO_TEST_SUITE(class__SelectClosure)

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::closure::SelectClosure              テスト対象クラス
 * @see sqlxx::closure::SelectClosure::to_string() テスト対象メンバ関数
 */
auto data_set_for_to_string() -> std::vector<DataSetElement>
{
    std::vector<std::vector<DataSetElement>> data_set_parts = {
        // clang-format off
        data_set_for_to_string_00(),
        data_set_for_to_string_01(),
        data_set_for_to_string_02(),
        data_set_for_to_string_03(),
        data_set_for_to_string_04(),
        data_set_for_to_string_05(),
        data_set_for_to_string_06(),
        data_set_for_to_string_07(),
        data_set_for_to_string_08(),
        data_set_for_to_string_09(),
        data_set_for_to_string_10(),
        data_set_for_to_string_11(),
        data_set_for_to_string_12(),
        data_set_for_to_string_13(),
        data_set_for_to_string_14(),
        data_set_for_to_string_15(),
        data_set_for_to_string_16()
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

BOOST_AUTO_TEST_SUITE_END(/* class__SelectClosure */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__closure */)

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__SELECT_CLOSURE_DATA_SET_HXX */
