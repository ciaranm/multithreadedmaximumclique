/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#include <clique/max_clique_params.hh>

#include <iostream>

using namespace clique;

auto clique::print_candidate(const MaxCliqueParams & params, unsigned size) -> void
{
    std::cout << "-- " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - params.start_time).count()
        << " found " << size << std::endl;
}

auto MaxCliqueResult::merge(const MaxCliqueResult & other) -> void
{
    nodes += other.nodes;
    donations += other.donations;
    top_nodes_done += other.top_nodes_done;
    if (other.size > size) {
        size = other.size;
        members = std::move(other.members);
    }
}

