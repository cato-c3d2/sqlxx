/*!
 * @file select-statement.class.h++
 */

#ifndef SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_HXX
#define SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_HXX

#include <string>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>

namespace sqlxx
{
inline namespace statement
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief "SELECT 文" の文法クラス
     */
    class SelectStatement
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        SelectStatement();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] select_clause "SELECT 句" の文法オブジェクト
         * @param[in] from_clause   "FROM 句" の文法オブジェクト
         */
        SelectStatement(
            clause::SelectClause select_clause,
            clause::FromClause   from_clause = {});

        /*!
         * @brief "SELECT 句" を設定する
         *
         * @param[in] select_clause "SELECT 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto select(clause::SelectClause select_clause) -> SelectStatement &;

        /*!
         * @brief "FROM 句" を設定する
         *
         * @param[in] from_clause "FROM 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto from(clause::FromClause from_clause) -> SelectStatement &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        /*!
         * @brief "SELECT 句"
         */
        clause::SelectClause _select_clause;

        /*!
         * @brief "FROM 句"
         */
        clause::FromClause _from_clause;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] select_statement "SELECT 文" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, SelectStatement const select_statement)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    SelectStatement::SelectStatement() : _select_clause(), _from_clause()
    {}

    SelectStatement::SelectStatement(
        clause::SelectClause select_clause, clause::FromClause from_clause)
        : _select_clause(select_clause), _from_clause(from_clause)
    {}

    auto SelectStatement::select(clause::SelectClause select_clause)
        -> SelectStatement &
    {
        this->_select_clause = select_clause;
        return *this;
    }

    auto SelectStatement::from(clause::FromClause from_clause)
        -> SelectStatement &
    {
        this->_from_clause = from_clause;
        return *this;
    }

    auto SelectStatement::to_string() const -> std::string
    {
        std::vector<std::string> clauses;

        if (this->_select_clause.empty()) {
            return "";
        }
        clauses.push_back(this->_select_clause.to_string());

        if (this->_from_clause.empty()) {
            return "";
        }
        clauses.push_back(this->_from_clause.to_string());

        std::string text      = "";
        std::string delimiter = "";
        for (auto && clause : clauses) {
            text += delimiter + clause;
            delimiter = " ";
        }
        return text;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, SelectStatement const select_statement)
        -> std::ostream &
    {
        out << select_statement.to_string();
        return out;
    }
} // namespace statement
} // namespace sqlxx

#endif // SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_HXX
