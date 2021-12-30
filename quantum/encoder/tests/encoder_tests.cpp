/* Copyright 2021 Balz Guenat
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
#include <algorithm>
#include <stdio.h>

extern "C" {
#include "encoder.h"
#include "encoder/tests/mock.h"
}

struct update {
    int8_t index;
    bool   clockwise;
};

<<<<<<< HEAD
uint8_t updates_array_idx = 0;
update  updates[32];

bool encoder_update_kb(uint8_t index, bool clockwise) {
    updates[updates_array_idx % 32] = {index, clockwise};
    updates_array_idx++;
=======
uint8_t uidx = 0;
update  updates[32];

bool encoder_update_kb(uint8_t index, bool clockwise) {
    updates[uidx % 32] = {index, clockwise};
    uidx++;
>>>>>>> c0de397925 (merge bedore pointerwork)
    return true;
}

bool setAndRead(pin_t pin, bool val) {
    setPin(pin, val);
    return encoder_read();
}

class EncoderTest : public ::testing::Test {};

TEST_F(EncoderTest, TestInit) {
<<<<<<< HEAD
    updates_array_idx = 0;
    encoder_init();
    EXPECT_EQ(pinIsInputHigh[0], true);
    EXPECT_EQ(pinIsInputHigh[1], true);
    EXPECT_EQ(updates_array_idx, 0);
}

TEST_F(EncoderTest, TestOneClockwise) {
    updates_array_idx = 0;
=======
    uidx = 0;
    encoder_init();
    EXPECT_EQ(pinIsInputHigh[0], true);
    EXPECT_EQ(pinIsInputHigh[1], true);
    EXPECT_EQ(uidx, 0);
}

TEST_F(EncoderTest, TestOneClockwise) {
    uidx = 0;
>>>>>>> c0de397925 (merge bedore pointerwork)
    encoder_init();
    // send 4 pulses. with resolution 4, that's one step and we should get 1 update.
    setAndRead(0, false);
    setAndRead(1, false);
    setAndRead(0, true);
    setAndRead(1, true);

<<<<<<< HEAD
    EXPECT_EQ(updates_array_idx, 1);
=======
    EXPECT_EQ(uidx, 1);
>>>>>>> c0de397925 (merge bedore pointerwork)
    EXPECT_EQ(updates[0].index, 0);
    EXPECT_EQ(updates[0].clockwise, true);
}

TEST_F(EncoderTest, TestOneCounterClockwise) {
<<<<<<< HEAD
    updates_array_idx = 0;
=======
    uidx = 0;
>>>>>>> c0de397925 (merge bedore pointerwork)
    encoder_init();
    setAndRead(1, false);
    setAndRead(0, false);
    setAndRead(1, true);
    setAndRead(0, true);

<<<<<<< HEAD
    EXPECT_EQ(updates_array_idx, 1);
=======
    EXPECT_EQ(uidx, 1);
>>>>>>> c0de397925 (merge bedore pointerwork)
    EXPECT_EQ(updates[0].index, 0);
    EXPECT_EQ(updates[0].clockwise, false);
}

TEST_F(EncoderTest, TestTwoClockwiseOneCC) {
<<<<<<< HEAD
    updates_array_idx = 0;
=======
    uidx = 0;
>>>>>>> c0de397925 (merge bedore pointerwork)
    encoder_init();
    setAndRead(0, false);
    setAndRead(1, false);
    setAndRead(0, true);
    setAndRead(1, true);
    setAndRead(0, false);
    setAndRead(1, false);
    setAndRead(0, true);
    setAndRead(1, true);
    setAndRead(1, false);
    setAndRead(0, false);
    setAndRead(1, true);
    setAndRead(0, true);

<<<<<<< HEAD
    EXPECT_EQ(updates_array_idx, 3);
=======
    EXPECT_EQ(uidx, 3);
>>>>>>> c0de397925 (merge bedore pointerwork)
    EXPECT_EQ(updates[0].index, 0);
    EXPECT_EQ(updates[0].clockwise, true);
    EXPECT_EQ(updates[1].index, 0);
    EXPECT_EQ(updates[1].clockwise, true);
    EXPECT_EQ(updates[2].index, 0);
    EXPECT_EQ(updates[2].clockwise, false);
}

TEST_F(EncoderTest, TestNoEarly) {
<<<<<<< HEAD
    updates_array_idx = 0;
=======
    uidx = 0;
>>>>>>> c0de397925 (merge bedore pointerwork)
    encoder_init();
    // send 3 pulses. with resolution 4, that's not enough for a step.
    setAndRead(0, false);
    setAndRead(1, false);
    setAndRead(0, true);
<<<<<<< HEAD
    EXPECT_EQ(updates_array_idx, 0);
    // now send last pulse
    setAndRead(1, true);
    EXPECT_EQ(updates_array_idx, 1);
=======
    EXPECT_EQ(uidx, 0);
    // now send last pulse
    setAndRead(1, true);
    EXPECT_EQ(uidx, 1);
>>>>>>> c0de397925 (merge bedore pointerwork)
    EXPECT_EQ(updates[0].index, 0);
    EXPECT_EQ(updates[0].clockwise, true);
}

TEST_F(EncoderTest, TestHalfway) {
<<<<<<< HEAD
    updates_array_idx = 0;
=======
    uidx = 0;
>>>>>>> c0de397925 (merge bedore pointerwork)
    encoder_init();
    // go halfway
    setAndRead(0, false);
    setAndRead(1, false);
<<<<<<< HEAD
    EXPECT_EQ(updates_array_idx, 0);
    // back off
    setAndRead(1, true);
    setAndRead(0, true);
    EXPECT_EQ(updates_array_idx, 0);
=======
    EXPECT_EQ(uidx, 0);
    // back off
    setAndRead(1, true);
    setAndRead(0, true);
    EXPECT_EQ(uidx, 0);
>>>>>>> c0de397925 (merge bedore pointerwork)
    // go all the way
    setAndRead(0, false);
    setAndRead(1, false);
    setAndRead(0, true);
    setAndRead(1, true);
    // should result in 1 update
<<<<<<< HEAD
    EXPECT_EQ(updates_array_idx, 1);
=======
    EXPECT_EQ(uidx, 1);
>>>>>>> c0de397925 (merge bedore pointerwork)
    EXPECT_EQ(updates[0].index, 0);
    EXPECT_EQ(updates[0].clockwise, true);
}
