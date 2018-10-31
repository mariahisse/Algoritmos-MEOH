TEST(CIRCULARLIST, first_has_value) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  ASSERT_TRUE(lista.HasValue(4));
}

TEST(CIRCULARLIST, second_has_value) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  ASSERT_TRUE(lista.HasValue(2));
}

TEST(CIRCULARLIST, third_has_value) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  ASSERT_TRUE(lista.HasValue(4));
}

TEST(CIRCULARLIST, fourth_has_value) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  ASSERT_TRUE(lista.HasValue(4));
}

TEST(CIRCULARLIST, fifth_has_value) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  ASSERT_TRUE(lista.HasValue(2));
}

TEST(CIRCULARLIST, first_no_has_value) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  ASSERT_FALSE(lista.HasValue(5));
}

TEST(CIRCULARLIST, second_no_has_value) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  ASSERT_FALSE(lista.HasValue(5));
}

TEST(CIRCULARLIST, first_get_node_position) {
  CircularList lista;
  lista.AddNodeAfter(2);
  ASSERT_EQ(lista.GetPosition(), 2);
}

TEST(CIRCULARLIST, second_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  ASSERT_EQ(lista.GetPosition(), 2);
}

TEST(CIRCULARLIST, third_get_node_position) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  ASSERT_EQ(lista.GetPosition(), 2);
}

TEST(CIRCULARLIST, fourth_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  ASSERT_EQ(lista.GetPosition(), 2);
}

TEST(CIRCULARLIST, fifth_get_node_position) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.PositionNext();
  ASSERT_EQ(lista.GetPosition(), 3);
}

TEST(CIRCULARLIST, sixth_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.PositionNext();
  ASSERT_EQ(lista.GetPosition(), 3);
}

TEST(CIRCULARLIST, seventh_get_node_position) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  lista.AddNodeAfter(5);
  lista.PositionPrevious();
  ASSERT_EQ(lista.GetPosition(), 5);
}

TEST(CIRCULARLIST, eighth_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.PositionPrevious();
  ASSERT_EQ(lista.GetPosition(), 3);
}

TEST(CIRCULARLIST, ninth_get_node_position) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  lista.AddNodeAfter(5);
  lista.PositionPrevious();
  lista.PositionPrevious();
  ASSERT_EQ(lista.GetPosition(), 4);
}

TEST(CIRCULARLIST, tenth_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  lista.AddNodeBefore(5);
  lista.PositionPrevious();
  lista.PositionPrevious();
  ASSERT_EQ(lista.GetPosition(), 4);
}

TEST(CIRCULARLIST, onze_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  lista.AddNodeBefore(5);
  lista.PositionPrevious();
  lista.PositionNext();
  lista.PositionPrevious();
  ASSERT_EQ(lista.GetPosition(), 3);
}

TEST(CIRCULARLIST, doze_get_node_position) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  lista.AddNodeAfter(5);
  lista.PositionPrevious();
  lista.PositionPrevious();
  lista.PositionNext();
  ASSERT_EQ(lista.GetPosition(), 5);
}

TEST(CIRCULARLIST, treze_get_node_position) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  lista.AddNodeBefore(5);
  lista.AddNodeBefore(6);
  lista.PositionPrevious();
  lista.PositionPrevious();
  lista.PositionPrevious();
  lista.PositionPrevious();
  ASSERT_EQ(lista.GetPosition(), 6);
}

TEST(CIRCULARLIST, get_node_empty_list) {
  CircularList lista;
  ASSERT_THROW(lista.GetPosition(), std::invalid_argument);
}

TEST(CIRCULARLIST, first_pop_last_node) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.AddNodeAfter(3);
  lista.AddNodeAfter(4);
  lista.PopPosition();
  ASSERT_EQ(lista.GetPosition(), 3);
}

TEST(CIRCULARLIST, second_pop_last_node) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.AddNodeBefore(3);
  lista.AddNodeBefore(4);
  lista.PopPosition();
  ASSERT_EQ(lista.GetPosition(), 4);
}

TEST(CIRCULARLIST, pop_last_empty) {
  CircularList lista;
  ASSERT_THROW(lista.PopPosition(), std::invalid_argument);
}

TEST(CIRCULARLIST, list_empty) {
  CircularList lista;
  ASSERT_TRUE(lista.position == NULL);
}

TEST(CIRCULARLIST, list_is_empty) {
  CircularList lista;
  ASSERT_TRUE(lista.IsEmpty());
}

TEST(CIRCULARLIST, pop_one_from_one) {
  CircularList lista;
  lista.AddNodeAfter(2);
  lista.PopPosition();
  ASSERT_TRUE(lista.IsEmpty());
}

TEST(CIRCULARLIST, pop_one_from_two) {
  CircularList lista;
  lista.AddNodeAfter(1);
  lista.AddNodeAfter(2);
  lista.PopPosition();
  lista.PopPosition();
  ASSERT_TRUE(lista.IsEmpty());
}

TEST(CIRCULARLIST, pop_two_from_one) {
  CircularList lista;
  lista.AddNodeBefore(2);
  lista.PopPosition();
  ASSERT_TRUE(lista.IsEmpty());
}

TEST(CIRCULARLIST, pop_two_from_two) {
  CircularList lista;
  lista.AddNodeBefore(1);
  lista.AddNodeBefore(2);
  lista.PopPosition();
  lista.PopPosition();
  ASSERT_TRUE(lista.IsEmpty());
}

TEST(CIRCULARLIST, first_not_is_empty) {
  CircularList lista;
  lista.AddNodeAfter(2);
  ASSERT_FALSE(lista.IsEmpty());
}

TEST(CIRCULARLIST, second_not_is_empty) {
  CircularList lista;
  lista.AddNodeBefore(2);
  ASSERT_FALSE(lista.IsEmpty());
}

TEST(NODES, first_inf_only) {
  Node node(2);
  ASSERT_TRUE(node.info == 2);
}

TEST(NODES, second_inf_only) {
  Node node(2);
  ASSERT_TRUE(node.next == NULL);
}

TEST(NODES, third_inf_only) {
  Node node(2);
  ASSERT_TRUE(node.previous == NULL);
}

TEST(NODES, first_inf_and_node) {
  Node node1(1);
  Node node2(2, &node1, &node1);
  ASSERT_TRUE(node2.info == 2);
}

TEST(NODES, second_inf_and_node) {
  Node node1(1);
  Node node2(2, &node1, &node1);
  ASSERT_TRUE(node2.info == 2);
  ASSERT_TRUE(node2.previous == &node1);
}

TEST(NODES, third_inf_and_node) {
  Node node1(1);
  Node node2(2, &node1, &node1);
  ASSERT_TRUE(node2.next == &node1);
}

TEST(NODES, first_many_nodes) {
  Node node1(1);
  Node node2(2, &node1);
  Node node3(3, &node1, &node2);
  ASSERT_TRUE(node3.info == 3);
}

TEST(NODES, second_many_nodes) {
  Node node1(1);
  Node node2(2, &node1);
  Node node3(3, &node1, &node2);
  ASSERT_TRUE(node3.previous == &node1);
}

TEST(NODES, third_many_nodes) {
  Node node1(1);
  Node node2(2, &node1);
  Node node3(3, &node1, &node2);
  ASSERT_TRUE(node3.next == &node2);
}
