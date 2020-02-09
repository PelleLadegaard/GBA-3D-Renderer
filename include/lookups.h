#pragma once

//Lookup table for degree to radian
const s8 lut_cos[] = {127,127,127,127,126,126,126,125,125,124,123,122,122,121,120,118,117,116,115,113,112,110,109,107,106,104,102,100,98,96,94,92,90,87,85,83,80,78,75,73,70,68,65,62,60,57,54,51,48,45,42,39,37,34,30,27,24,21,18,15,12,9,6,3,0,-4,-7,-10,-13,-16,-19,-22,-25,-28,-31,-35,-38,-40,-43,-46,-49,-52,-55,-58,-61,-63,-66,-69,-71,-74,-76,-79,-81,-84,-86,-88,-91,-93,-95,-97,-99,-101,-103,-105,-107,-108,-110,-111,-113,-114,-116,-117,-118,-119,-121,-122,-123,-123,-124,-125,-126,-126,-127,-127,-127,-128,-128,-128,-128,-128,-128,-128,-127,-127,-127,-126,-126,-125,-124,-123,-123,-122,-121,-119,-118,-117,-116,-114,-113,-111,-110,-108,-107,-105,-103,-101,-99,-97,-95,-93,-91,-88,-86,-84,-81,-79,-76,-74,-71,-69,-66,-63,-61,-58,-55,-52,-49,-46,-43,-40,-38,-35,-31,-28,-25,-22,-19,-16,-13,-10,-7,-4,0,3,6,9,12,15,18,21,24,27,30,34,37,39,42,45,48,51,54,57,60,62,65,68,70,73,75,78,80,83,85,87,90,92,94,96,98,100,102,104,106,107,109,110,112,113,115,116,117,118,120,121,122,122,123,124,125,125,126,126,126,127,127,127};
const s8 lut_sin[] = {0,3,6,9,12,15,18,21,24,27,30,34,37,39,42,45,48,51,54,57,60,62,65,68,70,73,75,78,80,83,85,87,90,92,94,96,98,100,102,104,106,107,109,110,112,113,115,116,117,118,120,121,122,122,123,124,125,125,126,126,126,127,127,127,127,127,127,127,126,126,126,125,125,124,123,122,122,121,120,118,117,116,115,113,112,110,109,107,106,104,102,100,98,96,94,92,90,87,85,83,80,78,75,73,70,68,65,62,60,57,54,51,48,45,42,39,37,34,30,27,24,21,18,15,12,9,6,3,0,-4,-7,-10,-13,-16,-19,-22,-25,-28,-31,-35,-38,-40,-43,-46,-49,-52,-55,-58,-61,-63,-66,-69,-71,-74,-76,-79,-81,-84,-86,-88,-91,-93,-95,-97,-99,-101,-103,-105,-107,-108,-110,-111,-113,-114,-116,-117,-118,-119,-121,-122,-123,-123,-124,-125,-126,-126,-127,-127,-127,-128,-128,-128,-128,-128,-128,-128,-127,-127,-127,-126,-126,-125,-124,-123,-123,-122,-121,-119,-118,-117,-116,-114,-113,-111,-110,-108,-107,-105,-103,-101,-99,-97,-95,-93,-91,-88,-86,-84,-81,-79,-76,-74,-71,-69,-66,-63,-61,-58,-55,-52,-49,-46,-43,-40,-38,-35,-31,-28,-25,-22,-19,-16,-13,-10,-7,-4};
const s8 lut_coshalf[] = {64,64,64,64,64,64,63,63,63,62,62,62,61,61,60,60,59,59,58,57,56,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,39,38,37,36,34,33,32,30,29,27,26,24,23,22,20,19,17,16,14,12,11,9,8,6,5,3,2,0,-2,-3,-5,-6,-8,-9,-11,-12,-14,-16,-17,-19,-20,-22,-23,-24,-26,-27,-29,-30,-32,-33,-34,-36,-37,-38,-39,-41,-42,-43,-44,-45,-46,-47,-48,-49,-50,-51,-52,-53,-54,-55,-56,-56,-57,-58,-59,-59,-60,-60,-61,-61,-62,-62,-62,-63,-63,-63,-64,-64,-64,-64,-64,-64,-64,-64,-64,-64,-64,-63,-63,-63,-62,-62,-62,-61,-61,-60,-60,-59,-59,-58,-57,-56,-56,-55,-54,-53,-52,-51,-50,-49,-48,-47,-46,-45,-44,-43,-42,-41,-39,-38,-37,-36,-34,-33,-32,-30,-29,-27,-26,-24,-23,-22,-20,-19,-17,-16,-14,-12,-11,-9,-8,-6,-5,-3,-2,0,2,3,5,6,8,9,11,12,14,16,17,19,20,22,23,24,26,27,29,30,32,33,34,36,37,38,39,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,56,57,58,59,59,60,60,61,61,62,62,62,63,63,63,64,64,64,64,64};