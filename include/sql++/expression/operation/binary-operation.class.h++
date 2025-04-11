/*!
 * @file binary-operation.class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_HXX

#include <stdexcept>
#include <string>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/expression.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/logical-operatable.class.h++>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪二項演算式≫を表現するクラス
     */
    class BinaryOperation :
        public virtual ConditionExpression,
        public virtual LogicalOperatable<BinaryOperation>
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        BinaryOperation();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] operation_kind ≪二項演算種別≫
         * @param[in] left_operand   左辺の≪式≫
         * @param[in] right_operand  右辺の≪式≫
         */
        BinaryOperation(
            BinaryOperationKind operation_kind,
            Expression const &  left_operand,
            Expression const &  right_operand);

        /*!
         * @brief コンストラクタ
         *
         * ≪二項演算種別≫のみを設定し、左辺の≪式≫及び右辺の≪式≫を後から設定する場合に使用する。 @n
         *
         * @param[in] operation_kind ≪二項演算種別≫
         */
        BinaryOperation(BinaryOperationKind operation_kind);

        /*!
         * @brief コンストラクタ
         *
         * ≪二項演算種別≫と左辺の≪式≫を設定し、右辺の≪式≫を後から設定する場合に使用する。 @n
         *
         * @param[in] operation_kind ≪二項演算種別≫
         * @param[in] left_operand   左辺の≪式≫
         */
        BinaryOperation(
            BinaryOperationKind operation_kind,
            Expression const &  left_operand);

        /*!
         * @brief デストラクタ
         */
        virtual ~BinaryOperation() override;

        /*!
         * @brief コピーコンストラクタ
         *
         * @param[in] origin コピー元のオブジェクト
         */
        BinaryOperation(BinaryOperation const & origin);

        /*!
         * @brief コピー代入演算子
         *
         * @param[in] origin コピー元のオブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto operator=(BinaryOperation const & origin) -> BinaryOperation &;

        /*!
         * @brief ≪二項演算種別≫を取得する
         *
         * @return ≪二項演算種別≫
         */
        auto operation_kind() const -> BinaryOperationKind;

        /*!
         * @brief ≪二項演算種別≫を設定する
         *
         * @param[in] operation_kind ≪二項演算種別≫
         *
         * @return このオブジェクトの参照
         */
        auto operation_kind(BinaryOperationKind operation_kind)
            -> BinaryOperation &;

        /*!
         * @brief 左辺の≪式≫を取得する
         *
         * このオブジェクトが保持する左辺の≪式≫を複製し、そのポインタを返却する。 @n
         *
         * @return 複製した左辺の≪式≫のポインタ
         */
        auto left_operand() const -> Expression *;

        /*!
         * @brief 左辺の≪式≫を設定する
         *
         * 引数として指定した≪式≫を複製し、そのポインタをこのオブジェクトの左辺の≪式≫として保持する。 @n
         *
         * @param[in] left_operand 左辺の≪式≫
         *
         * @return このオブジェクトの参照
         */
        auto left_operand(Expression const & left_operand) -> BinaryOperation &;

        /*!
         * @brief 右辺の≪式≫を取得する
         *
         * このオブジェクトが保持する右辺の≪式≫を複製し、そのポインタを返却する。 @n
         *
         * @return 複製した右辺の≪式≫のポインタ
         */
        auto right_operand() const -> Expression *;

        /*!
         * @brief 右辺の≪式≫を設定する
         *
         * 引数として指定した≪式≫を複製し、そのポインタをこのオブジェクトの右辺の≪式≫として保持する。 @n
         *
         * @param[in] right_operand 右辺の≪式≫
         *
         * @return このオブジェクトの参照
         */
        auto right_operand(Expression const & right_operand)
            -> BinaryOperation &;

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を、
         *         そうではない場合は @c false を返却する
         */
        auto empty() const -> bool;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

        /*!
         * @brief この式の文字列表現を返却する
         *
         * @return この式の文字列表現
         */
        virtual auto evaluate() const -> std::string override;

        /*!
         * @brief このオブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> BinaryOperation * override;

    private:
        /*!
         * @brief このオブジェクトにコピー元のオブジェクトを割り当てる
         *
         * このオブジェクトの各データメンバに、
         * @c origin の各データメンバを代入する。 @n
         * @n
         * NOTE コピーコンストラクタとコピー代入演算子の実装を共通化するために実装した。 @n
         *
         * @param[in] origin コピー元のオブジェクト
         */
        auto assignment(BinaryOperation const & origin) -> void;

    private:
        /*!
         * @brief ≪二項演算種別≫
         */
        BinaryOperationKind _operation_kind;

        /*!
         * @brief 左辺の≪式≫
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _left_operand;

        /*!
         * @brief 右辺の≪式≫
         */
        // TODO 暫定的に生のポインタを使用しているが、将来的にスマートポインタに変更する予定。
        Expression const * _right_operand;
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
     * @param[in] binary_operation ≪二項演算式≫のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, BinaryOperation const binary_operation)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    BinaryOperation::BinaryOperation()
        : BinaryOperation(BinaryOperationKind::None)
    {}

    BinaryOperation::BinaryOperation(
        BinaryOperationKind operation_kind,
        Expression const &  left_operand,
        Expression const &  right_operand)
        : _operation_kind(operation_kind)
        , _left_operand(left_operand.clone())
        , _right_operand(right_operand.clone())
    {}

    BinaryOperation::BinaryOperation(BinaryOperationKind operation_kind)
        : _operation_kind(operation_kind)
        , _left_operand(nullptr)
        , _right_operand(nullptr)
    {}

    BinaryOperation::BinaryOperation(
        BinaryOperationKind operation_kind, Expression const & left_operand)
        : _operation_kind(operation_kind)
        , _left_operand(left_operand.clone())
        , _right_operand(nullptr)
    {}

    BinaryOperation::~BinaryOperation()
    {
        if (this->_left_operand != nullptr) {
            delete this->_left_operand;
        }
        if (this->_right_operand != nullptr) {
            delete this->_right_operand;
        }
    }

    BinaryOperation::BinaryOperation(BinaryOperation const & origin)
    {
        this->assignment(origin);
    }

    auto BinaryOperation::operator=(BinaryOperation const & origin)
        -> BinaryOperation &
    {
        this->assignment(origin);
        return *this;
    }

    auto BinaryOperation::operation_kind() const -> BinaryOperationKind
    {
        return this->_operation_kind;
    }

    auto BinaryOperation::operation_kind(BinaryOperationKind operation_kind)
        -> BinaryOperation &
    {
        this->_operation_kind = operation_kind;
        return *this;
    }

    auto BinaryOperation::left_operand() const -> Expression *
    {
        return this->_left_operand != nullptr ? this->_left_operand->clone()
                                              : nullptr;
    }

    auto BinaryOperation::left_operand(Expression const & left_operand)
        -> BinaryOperation &
    {
        this->_left_operand = left_operand.clone();
        return *this;
    }

    auto BinaryOperation::right_operand() const -> Expression *
    {
        return this->_right_operand != nullptr ? this->_right_operand->clone()
                                               : nullptr;
    }

    auto BinaryOperation::right_operand(Expression const & right_operand)
        -> BinaryOperation &
    {
        this->_right_operand = right_operand.clone();
        return *this;
    }

    auto BinaryOperation::empty() const -> bool
    {
        return this->_operation_kind == BinaryOperationKind::None
               || this->_left_operand == nullptr
               || this->_right_operand == nullptr;
    }

    auto BinaryOperation::to_string() const -> std::string
    {
        if (this->empty()) {
            return {};
        }
        return this->evaluate();
    }

    auto BinaryOperation::evaluate() const -> std::string
    {
        if (this->_operation_kind == BinaryOperationKind::None) {
            throw std::runtime_error("'_operation_kind' is empty!");
        }
        if (this->_left_operand == nullptr) {
            throw std::runtime_error("'_left_operand' is null-pointer!");
        }
        if (this->_right_operand == nullptr) {
            throw std::runtime_error("'_right_operand' is null-pointer!");
        }

        return this->_left_operand->evaluate() + " "
               + sqlxx::expression::to_string(this->_operation_kind) + " "
               + this->_right_operand->evaluate();
    }

    auto BinaryOperation::clone() const -> BinaryOperation *
    {
        return new BinaryOperation { *this };
    }

    auto BinaryOperation::assignment(BinaryOperation const & origin) -> void
    {
        this->_operation_kind = origin._operation_kind;
        this->_left_operand   = (origin._left_operand != nullptr)
                                  ? origin._left_operand->clone()
                                  : nullptr;
        this->_right_operand = (origin._right_operand != nullptr)
                                   ? origin._right_operand->clone()
                                   : nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, BinaryOperation const binary_operation)
        -> std::ostream &
    {
        out << binary_operation.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__BINARY_OPERATION_CLASS_HXX
