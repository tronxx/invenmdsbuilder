object Frame_datospedimento: TFrame_datospedimento
  Left = 0
  Top = 0
  Width = 320
  Height = 163
  TabOrder = 0
  object lbl_serie: TLabel
    Left = 68
    Top = 29
    Width = 24
    Height = 13
    Caption = 'Serie'
  end
  object lbl_codigo: TLabel
    Left = 59
    Top = 6
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object lbl_seriemot: TLabel
    Left = 38
    Top = 53
    Width = 54
    Height = 13
    Caption = 'Serie Motor'
  end
  object lbl_pedimento: TLabel
    Left = 42
    Top = 77
    Width = 50
    Height = 13
    Caption = 'Pedimento'
  end
  object lbl_aduana: TLabel
    Left = 55
    Top = 101
    Width = 37
    Height = 13
    Caption = 'Aduana'
  end
  object lbl_fechaped: TLabel
    Left = 7
    Top = 125
    Width = 83
    Height = 13
    Caption = 'Fecha Pedimento'
  end
  object edt_serie: TEdit
    Left = 96
    Top = 27
    Width = 185
    Height = 21
    TabStop = False
    CharCase = ecUpperCase
    ReadOnly = True
    TabOrder = 1
  end
  object edt_codigo: TEdit
    Left = 96
    Top = 4
    Width = 185
    Height = 21
    TabStop = False
    CharCase = ecUpperCase
    ReadOnly = True
    TabOrder = 0
  end
  object edt_seriemot: TEdit
    Left = 96
    Top = 51
    Width = 185
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 2
  end
  object edt_pedimento: TEdit
    Left = 96
    Top = 75
    Width = 185
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 3
  end
  object edt_aduana: TEdit
    Left = 96
    Top = 99
    Width = 185
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 4
  end
  object date_fecha: TDateTimePicker
    Left = 96
    Top = 122
    Width = 185
    Height = 21
    CalAlignment = dtaLeft
    Date = 40953.5040020949
    Time = 40953.5040020949
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 5
  end
  object qry_datosped: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      
        'IDDATOSENT, IDENTRADA, TIPO, ALM, NUMERO, a.IDART, SERIE, IDSERI' +
        'EMOT,'
      'IDPEDTO, IDADUANA, FECHAPED'
      'from inv_datosent a'
      'where a.idart = :IDART and a.serie = :SERIE'
      ' ')
    UpdateObject = uqry_datosped
    Left = 10
    Top = 18
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDART'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SERIE'
        ParamType = ptUnknown
      end>
  end
  object uqry_datosped: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_datosent'
      'set'
      '  IDDATOSENT = :IDDATOSENT,'
      '  IDENTRADA = :IDENTRADA,'
      '  TIPO = :TIPO,'
      '  ALM = :ALM,'
      '  NUMERO = :NUMERO,'
      '  IDART = :IDART,'
      '  SERIE = :SERIE,'
      '  IDSERIEMOT = :IDSERIEMOT,'
      '  IDPEDTO = :IDPEDTO,'
      '  IDADUANA = :IDADUANA,'
      '  FECHAPED = :FECHAPED'
      'where'
      '  IDDATOSENT = :OLD_IDDATOSENT')
    InsertSQL.Strings = (
      'insert into inv_datosent'
      
        '  (IDDATOSENT, IDENTRADA, TIPO, ALM, NUMERO, IDART, SERIE, IDSER' +
        'IEMOT, '
      '   IDPEDTO, IDADUANA, FECHAPED)'
      'values'
      
        '  (:IDDATOSENT, :IDENTRADA, :TIPO, :ALM, :NUMERO, :IDART, :SERIE' +
        ', :IDSERIEMOT, '
      '   :IDPEDTO, :IDADUANA, :FECHAPED)')
    DeleteSQL.Strings = (
      'delete from inv_datosent'
      'where'
      '  IDDATOSENT = :OLD_IDDATOSENT')
    Left = 8
    Top = 48
  end
  object qry_idart: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select IDART, CODIGO, IDDESCRI, CIA'
      'from inv_invhist where codigo = :CODIGO and cia = :CIA'
      '')
    Left = 8
    Top = 88
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
