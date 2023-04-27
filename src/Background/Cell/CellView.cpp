#include "CellView.h"

CellView::CellView(const Cell& c) {
    if (!c.get_pass()) {
        cell = '/';
        return;
    }
    if (c.get_event() != nullptr) {
        cell = 'e';
        return;
    }
    cell = ' ';

}

char CellView::get_cell() const {
    return cell;
}