/// \file TFrame.cxx
/// \ingroup Gpad ROOT7
/// \author Axel Naumann <axel@cern.ch>
/// \date 2017-09-26
/// \warning This is part of the ROOT 7 prototype! It will change without notice. It might trigger earthquakes. Feedback
/// is welcome!

/*************************************************************************
 * Copyright (C) 1995-2017, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#include "ROOT/TFrame.hxx"

#include "ROOT/TLogger.hxx"
#include "ROOT/TPadUserAxis.hxx"

#include <cassert>

ROOT::Experimental::TFrame::TFrame(std::vector<std::unique_ptr<TPadUserAxisBase>> &&coords, const DrawingOpts &opts)
   : fUserCoord(std::move(coords)), fPalette(TPalette::GetPalette("default")), fPos(opts.fPos.Get()), fSize(opts.fSize.Get())
{}

void ROOT::Experimental::TFrame::GrowToDimensions(size_t nDimensions)
{
   std::size_t oldSize = fUserCoord.size();
   if (oldSize >= nDimensions)
      return;
   fUserCoord.resize(nDimensions);
   for (std::size_t idx = oldSize; idx < nDimensions; ++idx)
      if (!fUserCoord[idx])
         fUserCoord[idx].reset(new TPadCartesianUserAxis);
}
