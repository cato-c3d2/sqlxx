/*!
 * @file as-clause.class.h++
 */

#ifndef SQLXX__CLAUSE__AS_CLAUSE_CLASS_HXX
#define SQLXX__CLAUSE__AS_CLAUSE_CLASS_HXX

#include <string>

#include <sql++/identifier/naming-rule.class.h++>

namespace sqlxx
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief "AS 句" の文法クラス
     */
    class AsClause
    {
    public:
        /*!
         * @brief エイリアス名の型
         */
        using AliasNameType = std::string;

        /*!
         * @brief デフォルトコンストラクタ
         */
        AsClause();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] alias_name  エイリアス名
         */
        AsClause(AliasNameType alias_name);

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         */
        auto alias_name(AliasNameType alias_name) -> AsClause &;

        /*!
         * @brief エイリアス名を取得する
         *
         * @return エイリアス名
         */
        auto alias_name() const -> AliasNameType;

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を,
         *         そうではない場合は @c false を返却する
         */
        auto empty() const -> bool;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        /*!
         * @brief "AS 句"
         */
        AliasNameType _alias_name;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out        出力ストリーム
     * @param[in] as_clause  "AS 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, AsClause const as_clause)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    AsClause::AsClause() : _alias_name()
    {}

    AsClause::AsClause(AliasNameType alias_name) : _alias_name(alias_name)
    {}

    auto AsClause::alias_name() const -> AliasNameType
    {
        return this->_alias_name;
    }

    auto AsClause::alias_name(AliasNameType alias_name) -> AsClause &
    {
        this->_alias_name = alias_name;
        return *this;
    }

    auto AsClause::empty() const -> bool
    {
        bool is_legal;
        if (this->_alias_name.find(".") == std::string::npos) {
            is_legal = identifier::NamingRule::is_legal(this->_alias_name);
        } else {
            is_legal = identifier::NamingRule::is_legal(this->_alias_name, ".");
        }
        return ! is_legal;
    }

    auto AsClause::to_string() const -> std::string
    {
        if (this->empty()) {
            return "";
        }
        return "AS " + this->_alias_name;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, AsClause const as_clause)
        -> std::ostream &
    {
        out << as_clause.to_string();
        return out;
    }
} // namespace clause
} // namespace sqlxx

#endif // SQLXX__CLAUSE__AS_CLAUSE_CLASS_HXX
