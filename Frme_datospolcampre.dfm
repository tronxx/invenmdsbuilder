object Frame_datospolcampre: TFrame_datospolcampre
  Left = 0
  Top = 0
  Width = 679
  Height = 66
  TabOrder = 0
  object lbl_numero: TLabel
    Left = 15
    Top = 11
    Width = 22
    Height = 13
    Caption = 'Folio'
  end
  object Label6: TLabel
    Left = 134
    Top = 12
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object lbl_inivig: TLabel
    Left = 270
    Top = 12
    Width = 97
    Height = 13
    Caption = 'Vigencia a Partir del '
  end
  object Label8: TLabel
    Left = 6
    Top = 35
    Width = 46
    Height = 13
    Caption = 'Concepto'
  end
  object lbl_finvigencia: TLabel
    Left = 470
    Top = 12
    Width = 42
    Height = 13
    Caption = 'Hasta el '
    Visible = False
  end
  object edt_folio: TdxCurrencyEdit
    Left = 57
    Top = 7
    Width = 60
    TabOrder = 0
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object date_fecha: TDateTimePicker
    Left = 171
    Top = 7
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 1
  end
  object date_inivig: TDateTimePicker
    Left = 371
    Top = 7
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
  object edt_concepto: TEdit
    Left = 58
    Top = 31
    Width = 545
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 4
  end
  object date_finvigencia: TDateTimePicker
    Left = 515
    Top = 7
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
    Visible = False
  end
end
