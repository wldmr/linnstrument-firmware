// Pan
#define POSITION_CC_X 10
// Balance
#define POSITION_CC_Y 8

// TODO: Versions for Note on, hold and off.
void handlePositionCCs() {
    static const byte ccPerCol = 128 / (NUMCOLS - 1);
    static const byte ccPerRow = 128 / NUMROWS;
    signed char channel = sensorCell->channel;
    FocusCell cell = focus(sensorSplit, channel);
    const byte x = ccPerCol * (cell.col - 1);  // Col 0 is the left buttons
    const byte y = ccPerRow * cell.row;
    midiSendControlChange(POSITION_CC_X, x, channel);
    midiSendControlChange(POSITION_CC_Y, y, channel);
}
