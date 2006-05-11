/******************************************************************************/
/*                                                                            */
/*                             constant_atom.h                                */
/*                                                                            */
/*                        Matching Pursuit Library                            */
/*                                                                            */
/* R�mi Gribonval                                                             */
/* Sacha Krstulovic                                                           */
/* Sylvain Lesage                                             Mon Apr 03 2006 */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/*  Copyright (C) 2006 IRISA                                                  */
/*                                                                            */
/*  This program is free software; you can redistribute it and/or             */
/*  modify it under the terms of the GNU General Public License               */
/*  as published by the Free Software Foundation; either version 2            */
/*  of the License, or (at your option) any later version.                    */
/*                                                                            */
/*  This program is distributed in the hope that it will be useful,           */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/*  GNU General Public License for more details.                              */
/*                                                                            */
/*  You should have received a copy of the GNU General Public License         */
/*  along with this program; if not, write to the Free Software               */
/*  Foundation, Inc., 59 Temple Place - Suite 330,                            */
/*  Boston, MA  02111-1307, USA.                                              */
/*                                                                            */
/******************************************************************************/

/*****************************************************/
/*                                                   */
/* DEFINITION OF THE CONSTANT ATOM CLASS,            */
/*                                                   */
/*****************************************************/
/*
 * SVN log:
 *
 * $Author: sacha $
 * $Date$
 * $Revision$
 *
 */


#ifndef __constant_atom_h_
#define __constant_atom_h_


/*********************/
/* DIRAC ATOM CLASS  */
/*********************/

/**
 * \brief Constants are rectangular windows, of unit norm
 *
 */
class MP_Constant_Atom_c: public MP_Atom_c {

  /********/
  /* DATA */
  /********/

public:
  /* VOID */

  /***********/
  /* METHODS */
  /***********/

  /***************************/
  /* CONSTRUCTORS/DESTRUCTOR */
  /***************************/

public:

  /* Specific factory function */
  static MP_Constant_Atom_c* init( const MP_Chan_t setNumChans );

  /* File factory function */
  static MP_Constant_Atom_c* init( FILE *fid, const char mode );

protected:

  /* Void constructor */
  MP_Constant_Atom_c( void );

  /** \brief Global allocations of the vectors */
  int global_alloc( const MP_Chan_t setNumChans );

  /** \brief File reader */
  virtual int read( FILE *fid, const char mode );

public:

  /* Destructor */
  virtual ~MP_Constant_Atom_c( void );


  /***************************/
  /* OUTPUT METHOD           */
  /***************************/
  virtual int write( FILE *fid, const char mode );


  /***************************/
  /* OTHER METHODS           */
  /***************************/
  virtual char * type_name(void);

  virtual int info( FILE *fid );
  virtual int info();

  virtual void build_waveform( MP_Sample_t *outBuffer );

  virtual int add_to_tfmap( MP_TF_Map_c *tfmap, const char tfmapType );

  virtual int       has_field( int field );
  virtual MP_Real_t get_field( int field , MP_Chan_t chanIdx );

};


#endif /* __constant_atom_h_ */