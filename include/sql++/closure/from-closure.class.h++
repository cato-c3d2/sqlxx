/*!
 * @file from-closure.class.h++
 */

#ifndef SQLXX__CLOSURE__FROM_CLOSURE_CLASS_HXX
#define SQLXX__CLOSURE__FROM_CLOSURE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/specification/table.class.h++>

#include <string>

namespace sqlxx::closure
{
    /*!
     * @brief "FROM 句" の文法クラス
     */
    class FromClosure
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        FromClosure();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] table "テーブル指定" の文法オブジェクト
         */
        FromClosure(specification::Table table);

        /*!
         * @brief "テーブル指定" を設定する
         *
         * @param[in] table "テーブル指定" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto table(specification::Table table) -> FromClosure &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        specification::Table _table;
    };

    /**
     * @brief ストリーム出力演算
     *
     * @param[in] out          出力ストリーム
     * @param[in] from_closure "FROM 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, FromClosure const from_closure)
        -> std::ostream &;
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

namespace sqlxx::closure
{
    FromClosure::FromClosure() : _table()
    {}

    FromClosure::FromClosure(specification::Table table) : _table(table)
    {}

    auto FromClosure::table(specification::Table table) -> FromClosure &
    {
        this->_table = table;
        return *this;
    }

    auto FromClosure::to_string() const -> std::string
    {
        std::string const table = this->_table.to_string();
        if (table.empty()) {
            return "";
        }
        return "FROM " + table;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Function definition
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, FromClosure const from_closure)
        -> std::ostream &
    {
        out << from_closure.to_string();
        return out;
    }
}

#endif // SQLXX__CLOSURE__FROM_CLOSURE_CLASS_HXX